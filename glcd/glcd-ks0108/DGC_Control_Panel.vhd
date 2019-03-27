library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity KEY_read is
			
port (

---	KEYPAD INTERFACE SIGNALS--------
		   ROW_KEY  	: inout std_logic_vector (4 downto 0);
		   COL_KEY 		: in std_logic_vector (4 downto 0); 
		   LCD_EN		: OUT std_logic;
------------------------------------
--- SYSTEM CONTROL INTERFACE SIGNALS
		   SYS_CLK 					: in std_logic;
		   CPLD_EN 					: in std_logic;
		   SYS_RST 					: in std_logic;
		   ACTIVE_PULSE				: out std_logic;
------------------------------------		   
--- CPU to PLD SPI INTERFACE SIGNALS 
		   SPI_CLK						: in STD_LOGIC;
		   SPI_MOSI   					: in STD_LOGIC;
		   SPI_MISO				 				: out STD_LOGIC;  
           KEY_SPI_CS, CS_LCD_SPI, LED_SPI_CS	: in  STD_LOGIC;
------------------------------------		   
--- SPI LCD interface signals
           LCD_SPI_CS, LCD_SPI_CLK, LCD_SPI_MOSI : out std_logic;
------------------------------------
--- LED INTERFACE SIGNALS-----------   
			LED_REG 				: out std_logic_vector(27 downto 0)


);
end KEY_read;		   

architecture BEHAVIOR of KEY_read is
--signal ACTIVE_PULSE				: std_logic;
--signal SPI_MISO				 	: STD_LOGIC;  
signal COL_NUMB : integer range 0 to 255;
signal KEY_TIME	: integer range 0 to 65000;
signal KEY_REG	: integer range 0 to 255;
signal KEY_CNT  : integer range 0 to 4;
signal CLK_CNT : integer range 0 to 9000;

signal KEY_EN, FLT_SPI_CLK		: std_logic;
signal SPI_MISO_KEY, KEY_CLK 	: std_logic;
signal SREG, KEY_BUF    		: std_logic_vector (7 downto 0); 
signal FLT_CNT	 				: std_logic_vector (4 downto 0);

--signal SEND_REG			: std_logic_vector (BIT_NUMBERS downto 0);
---
signal SREG_IN  : std_logic_vector (31 downto 0); 
signal counter : integer range 0 to 31;
signal RES_FLG : STD_LOGIC;
signal SPI_MISO_LED : STD_LOGIC;
---
begin

process (KEY_EN, COL_KEY(4 downto 0))
begin
if KEY_EN'event and KEY_EN = '1' then
	case COL_KEY is
		when "10000" => COL_NUMB <= 1;
		when "01000" => COL_NUMB <= 6;
		when "00100" => COL_NUMB <= 11;
		when "00010" => COL_NUMB <= 16;
		when "00001" => COL_NUMB <= 21;
		when others  => COL_NUMB <= 0;
	end case;	
end if;		
end process;
--
process (KEY_CLK, KEY_CNT, COL_NUMB, COL_KEY)
begin
		if COL_NUMB /= 0 then
			if COL_KEY /= "00000" then
				if KEY_CLK'event and KEY_CLK='1' then
					case KEY_CNT is
						when 0 => ROW_KEY <= "01111";
						when 1 => ROW_KEY <= "10111";
						when 2 => ROW_KEY <= "11011";
						when 3 => ROW_KEY <= "11101";
						when 4 => ROW_KEY <= "11110";
						when others => ROW_KEY <= "11111";
					end case;
					KEY_REG <= COL_NUMB + KEY_CNT;
					KEY_CNT <= KEY_CNT + 1;
				 end if;
			else KEY_BUF <= conv_std_logic_vector(KEY_REG, 8);
				 KEY_CNT <= 0;
				 ROW_KEY <= "11111";
			end if;
	     else
			KEY_CNT <= 0;
		    KEY_REG <= 0;
			KEY_BUF <= "00000000";
		end if;	
end process;

process (CPLD_EN, SYS_CLK, KEY_EN, KEY_TIME)
begin
if CPLD_EN = '1' then	
	if SYS_CLK'event and SYS_CLK = '1' then
		if KEY_TIME = 65000 then
		   KEY_EN 	<='1';
		   KEY_TIME <= 0;
		elsif KEY_TIME = 53000 then
		   KEY_EN <='0';
		   KEY_TIME <= KEY_TIME +1;	
		else
		   KEY_TIME <= KEY_TIME +1;
		end if;
	end if;	
else
	   KEY_TIME <= 0;
	   KEY_EN   <= '0';
end if;
ACTIVE_PULSE <= KEY_EN;	
end process;

---------------- KEYPAD clock forming module

process (KEY_EN, SYS_CLK, CLK_CNT)
begin
	if KEY_EN = '1' then
		if SYS_CLK'event and SYS_CLK = '1' then
		   if CLK_CNT  = 9000 then
			  KEY_CLK <= '1';
			  CLK_CNT <= 0;
		   elsif CLK_CNT = 5000 then
			   KEY_CLK <= '0';
			   CLK_CNT <= CLK_CNT + 1;
		   else 
				CLK_CNT <= CLK_CNT +1;
		   end if;
		 end if;  
	else
		CLK_CNT <= 0;
		KEY_CLK <= '0';
	end if;
LCD_EN <= KEY_CLK;	
end process;

-- The module sends SPI KEY register out		
-----------------------------------------------------------------	
process (FLT_SPI_CLK, KEY_SPI_CS, KEY_BUF)
begin	IF KEY_SPI_CS = '1' then
			SREG <= KEY_BUF;
			SPI_MISO_KEY <= '1';
		ELSIF FLT_SPI_CLK'EVENT AND FLT_SPI_CLK = '1' THEN
				SPI_MISO_KEY <= SREG(7);
				SREG(7 DOWNTO 0) <= SREG(6 DOWNTO 0) & '1';
		END IF;
END PROCESS;


---------------- SPI clock filtering module

process (CPLD_EN, SPI_CLK, FLT_CNT, SYS_CLK)
variable FLT_CLK : std_logic;
begin
if CPLD_EN = '1' then
		if SYS_CLK'event and SYS_CLK = '1' then
		   if SPI_CLK = '1' then
				if FLT_CNT = "11111" then FLT_CLK := '1';
			  	else FLT_CNT (4 downto 0) <= FLT_CNT(3 downto 0) & '1';
				end if;
		   else
				if FLT_CNT = "00000" then
				   FLT_CLK := '0';
				else FLT_CNT (4 downto 0) <='0' & FLT_CNT(4 downto 1);
				end if;
		   end if;  
	    end if;	
else 
	FLT_CNT <= "00000";
    FLT_CLK :='0';
end if;
FLT_SPI_CLK <= FLT_CLK;	
end process;

------Module transfers the SPI messages to the SPI LCD --------
process (CPLD_EN, CS_LCD_SPI, SPI_MOSI, FLT_SPI_CLK) -- filtered SPI_CLK used
begin
if CPLD_EN = '1' then
	if  CS_LCD_SPI = '0' then
		LCD_SPI_CS   <= '1';
		LCD_SPI_MOSI <= SPI_MOSI;
		LCD_SPI_CLK <= FLT_SPI_CLK;
	else
		LCD_SPI_CS   <= '0';
		LCD_SPI_MOSI <= '0';
		LCD_SPI_CLK  <= '0';
	end if;	
else
		LCD_SPI_CS   <= '0';
		LCD_SPI_MOSI <= '0';
		LCD_SPI_CLK  <= '0';
end if;		
end process;	
---------------------------------------------------------------
			
process (CPLD_EN, FLT_SPI_CLK, LED_SPI_CS, SPI_MOSI)
begin
	IF CPLD_EN ='1' then
		IF LED_SPI_CS = '0' then
		   IF FLT_SPI_CLK'EVENT AND FLT_SPI_CLK ='0' THEN
				if counter < 31 then
					RES_FLG <= '0';
					SPI_MISO_LED <= SPI_MOSI;
					SREG_IN(31 DOWNTO 0) <= SREG_IN(30 DOWNTO 0) & SPI_MOSI;
					counter <= counter + 1;
				elsif counter = 31 then
				RES_FLG <='1';
				counter <= 0;
				SPI_MISO_LED <='1';
				else RES_FLG <= '0';
				SPI_MISO_LED <= '1';
				end if;
			end if;
		else counter  <=  0;
			 RES_FLG  <= '0';
			 SPI_MISO_LED <= '1'; 
		end if;
	else counter <= 0;
	     RES_FLG <= '0';
		 SREG_IN (31 downto 0) <= (others => '0');
		 SPI_MISO_LED <= '1';
	end if;	 
END PROCESS;

process (CPLD_EN, RES_FLG, SREG_IN, SYS_CLK)
begin
if CPLD_EN = '1' then
	if RES_FLG= '1' then
		if SYS_CLK'event and SYS_CLK= '1' then
			LED_REG(27 downto 0) <= SREG_IN (31 downto 4);
		end if;	
	else
	end if;
else LED_REG (27 downto 0) <= (others => '0');
end if;
end process;	

Process (LED_SPI_CS, KEY_SPI_CS, CPLD_EN, SPI_MISO_LED, SPI_MISO_KEY)
begin
	IF CPLD_EN = '1' then
	   if LED_SPI_CS = '0' then 
			SPI_MISO <= SPI_MISO_LED;
	   elsif KEY_SPI_CS = '0' then 
			SPI_MISO <= SPI_MISO_KEY;
	   else 
			SPI_MISO <= 'Z';
	   end if;
	else
		SPI_MISO <= 'Z';
	end if;
end process;
end architecture;
	
	
	
	