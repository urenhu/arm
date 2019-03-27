#ifndef __ASCII24X12_H__
#define __ASCII24X12_H__

struct  typFNT_ASCII24                 // ������ģ���ݽṹ 
{
	unsigned char  Index;        // ������������	
	unsigned char  Msk[48];        // ���������� 
};

struct  typFNT_ASCII24 codeASCII_24[] = 
{
	/*
	Space(0) !(1) "(2) #(3) $(4) %(5) &(6) '(7)
	((8) )(9) *(10) +(11) ,(12) -(13) .(14) /(15)
	0(16) 1(17) 2(18) 3(19) 4(20) 5(21) 6(22) 7(23)
	8(24) 9(25) :(26) ;(27) <(28) =(29) >(30) ?(31)
	@(32) A(33) B(34) C(35) D(36) E(37) F(38) G(39)
	H(40) I(41) J(42) K(43) L(44) M(45) N(46) O(47)
	P(48) Q(49) R(50) S(51) T(52) U(53) V(54) W(55)
	X(56) Y(57) Z(58) [(59) \(60) ](61) ^(62) _(63)
	`(64) a(65) b(66) c(67) d(68) e(69) f(70) g(71)
	h(72) i(73) j(74) k(75) l(76) m(77) n(78) o(79)
	p(80) q(81) r(82) s(83) t(84) u(85) v(86) w(87)
	x(88) y(89) z(90) {(91) |(92) }(93) ~(94)
	*/
	' ',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'!',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,
	0x07,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'"',
	0x00,0x00,0x00,0x00,0x06,0x60,0x06,0x60,0x0C,0xC0,0x19,0x80,0x11,0x00,0x22,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'#',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x40,0x10,0x40,0x10,0x40,
	0x10,0x40,0x7F,0xE0,0x7F,0xE0,0x10,0x40,0x10,0x40,0x20,0x80,0x20,0x80,0x7F,0xE0,
	0x7F,0xE0,0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'$',
	0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x02,0x00,0x0F,0x80,0x1A,0xC0,0x32,0xC0,
	0x32,0xC0,0x32,0x00,0x1A,0x00,0x0E,0x00,0x07,0x00,0x03,0x80,0x03,0x80,0x02,0xC0,
	0x32,0xC0,0x32,0xC0,0x32,0xC0,0x12,0x80,0x0F,0x00,0x02,0x00,0x02,0x00,0x00,0x00,

	'%',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xC0,0x50,0x80,0x88,0x80,
	0x89,0x00,0x89,0x00,0x8B,0x00,0x8A,0x00,0x5F,0xC0,0x75,0x40,0x06,0x20,0x0A,0x20,
	0x0A,0x20,0x1A,0x20,0x12,0x20,0x11,0x40,0x21,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'&',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x26,0x00,0x26,0x00,
	0x26,0x00,0x26,0x00,0x25,0xC0,0x38,0x80,0x30,0x80,0x58,0x80,0x49,0x00,0xCD,0x00,
	0xC7,0x00,0xC6,0x00,0xC3,0x00,0x65,0x20,0x38,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'\'',
	0x00,0x00,0x00,0x00,0x30,0x00,0x38,0x00,0x08,0x00,0x08,0x00,0x10,0x00,0x60,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'(',
	0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x40,0x00,0x80,0x01,0x80,0x01,0x00,0x03,0x00,
	0x03,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
	0x03,0x00,0x03,0x00,0x01,0x00,0x01,0x80,0x00,0x80,0x00,0x40,0x00,0x20,0x00,0x00,

	')',
	0x00,0x00,0x00,0x00,0x40,0x00,0x20,0x00,0x10,0x00,0x18,0x00,0x08,0x00,0x0C,0x00,
	0x0C,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
	0x0C,0x00,0x0C,0x00,0x08,0x00,0x18,0x00,0x10,0x00,0x20,0x00,0x40,0x00,0x00,0x00,
	
	'*',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x02,0x00,
	0x02,0x00,0x72,0x70,0x3A,0xE0,0x0F,0x80,0x0F,0x80,0x3A,0xE0,0x72,0x70,0x02,0x00,
	0x02,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'+',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
	0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x7F,0xF0,0x02,0x00,0x02,0x00,0x02,0x00,
	0x02,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	',',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x30,0x00,0x38,0x00,0x08,0x00,0x08,0x00,0x10,0x00,0x60,0x00,

	'-',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'.',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x38,0x00,0x38,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'/',
	0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x60,0x00,0x40,0x00,0xC0,0x00,0x80,0x00,0x80,
	0x01,0x00,0x01,0x00,0x02,0x00,0x02,0x00,0x06,0x00,0x04,0x00,0x04,0x00,0x08,0x00,
	0x08,0x00,0x10,0x00,0x10,0x00,0x30,0x00,0x20,0x00,0x60,0x00,0x40,0x00,0x00,0x00,

	'0',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x19,0x80,0x30,0xC0,
	0x30,0xC0,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,
	0x60,0x60,0x30,0xC0,0x30,0xC0,0x19,0x80,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'1',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x06,0x00,0x3E,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'2',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x00,0x21,0x80,0x40,0xC0,
	0x60,0xC0,0x60,0xC0,0x00,0xC0,0x01,0x80,0x01,0x80,0x03,0x00,0x04,0x00,0x08,0x00,
	0x10,0x40,0x20,0x40,0x40,0x40,0x7F,0xC0,0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'3',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x23,0x00,0x61,0x80,
	0x61,0x80,0x61,0x80,0x01,0x80,0x03,0x00,0x0E,0x00,0x01,0x80,0x00,0x80,0x00,0xC0,
	0x60,0xC0,0x60,0xC0,0x60,0xC0,0x21,0x80,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'4',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x80,0x03,0x80,0x03,0x80,
	0x05,0x80,0x09,0x80,0x09,0x80,0x11,0x80,0x21,0x80,0x21,0x80,0x41,0x80,0x7F,0xE0,
	0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

	'5',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0xC0,0x20,0x00,
	0x20,0x00,0x20,0x00,0x20,0x00,0x2F,0x00,0x31,0x80,0x20,0xC0,0x00,0xC0,0x00,0xC0,
	0x60,0xC0,0x60,0xC0,0x41,0x80,0x21,0x80,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'6',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x18,0xC0,0x30,0xC0,
	0x30,0x00,0x20,0x00,0x60,0x00,0x67,0x80,0x68,0xC0,0x70,0x60,0x60,0x60,0x60,0x60,
	0x60,0x60,0x20,0x60,0x30,0x40,0x18,0xC0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'7',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xE0,0x3F,0xE0,0x30,0x40,
	0x20,0x80,0x20,0x80,0x00,0x80,0x01,0x00,0x01,0x00,0x02,0x00,0x02,0x00,0x02,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'8',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x30,0xC0,0x60,0x60,
	0x60,0x60,0x60,0x60,0x70,0x40,0x3C,0xC0,0x0F,0x00,0x33,0x80,0x20,0xC0,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x30,0xC0,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'9',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x30,0x80,0x30,0xC0,
	0x60,0x40,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0xE0,0x31,0x60,0x1E,0x60,0x00,0x60,
	0x00,0xC0,0x00,0xC0,0x30,0x80,0x31,0x80,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	':',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	';',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x00,0x02,0x00,0x04,0x00,0x00,0x00,

	'<',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x40,0x00,0x80,0x01,0x00,
	0x02,0x00,0x04,0x00,0x08,0x00,0x10,0x00,0x20,0x00,0x10,0x00,0x08,0x00,0x04,0x00,
	0x02,0x00,0x01,0x00,0x00,0x80,0x00,0x40,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,

	'=',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'>',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x10,0x00,0x08,0x00,0x04,0x00,
	0x02,0x00,0x01,0x00,0x00,0x80,0x00,0x40,0x00,0x20,0x00,0x40,0x00,0x80,0x01,0x00,
	0x02,0x00,0x04,0x00,0x08,0x00,0x10,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'?',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x80,0x30,0xC0,0x40,0x60,0x40,0x60,
	0x60,0x60,0x60,0x60,0x00,0xC0,0x01,0x80,0x06,0x00,0x04,0x00,0x04,0x00,0x04,0x00,
	0x00,0x00,0x00,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'@',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x1C,0x60,0x10,0x20,
	0x33,0x50,0x26,0xD0,0x64,0x90,0x64,0x90,0x68,0x90,0x68,0x90,0x69,0x90,0x69,0xA0,
	0x66,0xC0,0x30,0x10,0x30,0x20,0x18,0x40,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'A',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x00,0x0E,0x00,
	0x0B,0x00,0x0B,0x00,0x13,0x00,0x11,0x80,0x11,0x80,0x11,0x80,0x1F,0x80,0x20,0xC0,
	0x20,0xC0,0x20,0xC0,0x20,0x60,0x60,0x60,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

	'B',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x61,0x80,0x60,0xC0,
	0x60,0xC0,0x60,0xC0,0x60,0xC0,0x61,0x80,0x7F,0x00,0x60,0xC0,0x60,0x40,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0xC0,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'C',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x18,0x60,0x30,0x20,
	0x30,0x20,0x20,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,
	0x60,0x20,0x30,0x20,0x30,0x40,0x18,0x80,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'D',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x61,0x80,0x60,0xC0,
	0x60,0xC0,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,
	0x60,0x60,0x60,0xC0,0x60,0xC0,0x63,0x80,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'E',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xC0,0x60,0x40,0x60,0x20,
	0x60,0x00,0x60,0x00,0x61,0x00,0x61,0x00,0x7F,0x00,0x61,0x00,0x61,0x00,0x60,0x00,
	0x60,0x00,0x60,0x20,0x60,0x20,0x60,0x40,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'F',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xC0,0x60,0xC0,0x60,0x20,
	0x60,0x20,0x60,0x00,0x61,0x00,0x61,0x00,0x7F,0x00,0x61,0x00,0x61,0x00,0x60,0x00,
	0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'G',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x40,0x18,0xC0,0x30,0x40,
	0x30,0x40,0x20,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x63,0xF0,0x60,0xC0,
	0x60,0xC0,0x30,0xC0,0x30,0xC0,0x18,0xC0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'H',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0x60,0x60,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7F,0xE0,0x60,0x60,0x60,0x60,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

	'I',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x06,0x00,0x06,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'J',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x01,0x80,0x01,0x80,
	0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
	0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x61,0x80,0x63,0x00,0x3E,0x00,

	'K',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0xE0,0x60,0x80,0x61,0x00,
	0x62,0x00,0x62,0x00,0x64,0x00,0x6C,0x00,0x7C,0x00,0x76,0x00,0x67,0x00,0x63,0x00,
	0x63,0x80,0x61,0x80,0x60,0xC0,0x60,0xE0,0xF1,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

	'L',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x60,0x00,0x60,0x00,
	0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,
	0x60,0x00,0x60,0x20,0x60,0x20,0x60,0x40,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'M',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0x70,0xE0,0x70,0xE0,
	0x70,0xE0,0x59,0x60,0x59,0x60,0x59,0x60,0x59,0x60,0x5A,0x60,0x4E,0x60,0x4E,0x60,
	0x4E,0x60,0x4E,0x60,0x44,0x60,0x44,0x60,0xE4,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

	'N',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x70,0x70,0x20,0x70,0x20,
	0x58,0x20,0x58,0x20,0x4C,0x20,0x46,0x20,0x46,0x20,0x43,0x20,0x43,0x20,0x41,0xA0,
	0x40,0xE0,0x40,0xE0,0x40,0x60,0x40,0x60,0xE0,0x20,0x00,0x00,0x00,0x00,0x00,0x00,

	'O',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x19,0x80,0x30,0xC0,
	0x30,0x40,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,
	0x60,0x60,0x30,0x40,0x30,0xC0,0x19,0x80,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'P',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x80,0x60,0xC0,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0xC0,0x7F,0x80,0x60,0x00,0x60,0x00,
	0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	
	'Q',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x19,0x80,0x30,0xC0,
	0x30,0x40,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,
	0x6E,0x60,0x32,0x40,0x31,0xC0,0x11,0x80,0x0F,0x80,0x01,0xE0,0x00,0xC0,0x00,0x00,

	'R',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x80,0x60,0xC0,0x60,0x60,
	0x60,0x60,0x60,0x60,0x60,0x60,0x60,0xC0,0x7F,0x00,0x66,0x00,0x63,0x00,0x63,0x00,
	0x61,0x80,0x61,0x80,0x60,0xC0,0x60,0xC0,0xF0,0x70,0x00,0x00,0x00,0x00,0x00,0x00,

	'S',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x30,0xE0,0x60,0x20,
	0x60,0x20,0x60,0x00,0x70,0x00,0x3C,0x00,0x0F,0x00,0x03,0xC0,0x00,0xC0,0x00,0x60,
	0x40,0x60,0x40,0x60,0x60,0x60,0x70,0xC0,0x4F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'T',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0x46,0x20,0x86,0x10,
	0x86,0x10,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'U',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x70,0x60,0x20,0x60,0x20,
	0x60,0x20,0x60,0x20,0x60,0x20,0x60,0x20,0x60,0x20,0x60,0x20,0x60,0x20,0x60,0x20,
	0x60,0x20,0x60,0x20,0x60,0x20,0x30,0x40,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'V',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF0,0x70,0x60,0x30,0x40,
	0x30,0x40,0x30,0x40,0x30,0x80,0x18,0x80,0x18,0x80,0x18,0x80,0x18,0x80,0x0D,0x00,
	0x0D,0x00,0x0D,0x00,0x0F,0x00,0x06,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'W',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF7,0x70,0x66,0x20,0x66,0x20,
	0x66,0x40,0x66,0x40,0x67,0x40,0x37,0x40,0x37,0x40,0x3B,0x80,0x3B,0x80,0x3B,0x80,
	0x3B,0x80,0x39,0x80,0x11,0x00,0x11,0x00,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'X',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x79,0xE0,0x30,0xC0,0x18,0x80,
	0x18,0x80,0x19,0x00,0x0D,0x00,0x0E,0x00,0x06,0x00,0x06,0x00,0x07,0x00,0x0B,0x00,
	0x0B,0x80,0x19,0x80,0x11,0x80,0x30,0xC0,0x79,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

	'Y',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF0,0x70,0x60,0x30,0x40,
	0x30,0x80,0x18,0x80,0x18,0x80,0x0D,0x00,0x0D,0x00,0x0E,0x00,0x06,0x00,0x06,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'Z',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x20,0xC0,0x41,0xC0,
	0x01,0x80,0x03,0x80,0x03,0x00,0x03,0x00,0x06,0x00,0x06,0x00,0x0C,0x00,0x0C,0x00,
	0x18,0x00,0x18,0x20,0x38,0x20,0x30,0x40,0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'[',
	0x00,0x00,0x00,0x00,0x07,0xE0,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,
	0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,
	0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x07,0xE0,0x00,0x00,

	'\\',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
	0x08,0x00,0x08,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x02,0x00,0x02,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x00,0x80,0x00,0x80,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x20,

	']',
	0x00,0x00,0x00,0x00,0x3F,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x3F,0x00,0x00,0x00,

	'^',
	0x00,0x00,0x00,0x00,0x07,0x00,0x0D,0x80,0x10,0x40,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'_',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xF0,

	'`',
	0x00,0x00,0x00,0x00,0x18,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'a',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0x80,0x30,0xC0,0x30,0xC0,0x07,0xC0,0x1C,0xC0,0x30,0xC0,
	0x60,0xC0,0x60,0xC0,0x60,0xC0,0x71,0xD0,0x3E,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

	'b',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x70,0x00,0x30,0x00,0x30,0x00,
	0x30,0x00,0x30,0x00,0x33,0x80,0x3C,0xC0,0x38,0x60,0x30,0x60,0x30,0x60,0x30,0x60,
	0x30,0x60,0x30,0x60,0x30,0x40,0x38,0xC0,0x2F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'c',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0x00,0x31,0x80,0x31,0x80,0x61,0x80,0x60,0x00,0x60,0x00,
	0x60,0x00,0x60,0x40,0x30,0x40,0x30,0x80,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'd',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x01,0xC0,0x00,0xC0,0x00,0xC0,
	0x00,0xC0,0x00,0xC0,0x1E,0xC0,0x31,0xC0,0x30,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,
	0x60,0xC0,0x60,0xC0,0x20,0xC0,0x31,0xE0,0x1E,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'e',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0x80,0x18,0xC0,0x10,0x60,0x30,0x60,0x3F,0xE0,0x30,0x00,
	0x30,0x00,0x30,0x00,0x18,0x20,0x1C,0x40,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'f',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x06,0x60,0x0C,0x60,
	0x0C,0x00,0x0C,0x00,0x7F,0xC0,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
	0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'g',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0x70,0x19,0x90,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x19,0x80,
	0x1F,0x00,0x30,0x00,0x3E,0x00,0x1F,0xC0,0x60,0x60,0x60,0x60,0x70,0xE0,0x1F,0x80,

	'h',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x70,0x00,0x30,0x00,0x30,0x00,
	0x30,0x00,0x30,0x00,0x37,0x80,0x38,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,
	0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x79,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

	'i',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3E,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'j',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x01,0x80,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
	0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x33,0x00,0x3E,0x00,

	'k',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x70,0x00,0x30,0x00,0x30,0x00,
	0x30,0x00,0x30,0x00,0x33,0xC0,0x31,0x00,0x33,0x00,0x32,0x00,0x36,0x00,0x3E,0x00,
	0x3B,0x00,0x33,0x00,0x31,0x80,0x31,0x80,0x79,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

	'l',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x3E,0x00,0x06,0x00,0x06,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
	0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'm',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xEE,0xE0,0x77,0x60,0x66,0x60,0x66,0x60,0x66,0x60,0x66,0x60,
	0x66,0x60,0x66,0x60,0x66,0x60,0x66,0x60,0xF7,0x70,0x00,0x00,0x00,0x00,0x00,0x00,

	'n',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x73,0x80,0x3C,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,
	0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x79,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

	'o',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0x00,0x19,0x80,0x30,0xC0,0x60,0x60,0x60,0x60,0x60,0x60,
	0x60,0x60,0x60,0x60,0x30,0xC0,0x30,0xC0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'p',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x77,0x80,0x38,0xC0,0x30,0x60,0x30,0x60,0x30,0x60,0x30,0x60,
	0x30,0x60,0x30,0x60,0x30,0xC0,0x38,0xC0,0x37,0x80,0x30,0x00,0x30,0x00,0x7C,0x00,

	'q',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x1E,0x40,0x31,0xC0,0x30,0xC0,0x60,0xC0,0x60,0xC0,0x60,0xC0,
	0x60,0xC0,0x60,0xC0,0x20,0xC0,0x31,0xC0,0x1E,0xC0,0x00,0xC0,0x00,0xC0,0x03,0xE0,

	'r',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xF9,0xE0,0x1A,0x60,0x1C,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
	0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	's',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0F,0xE0,0x18,0x60,0x30,0x20,0x30,0x00,0x1C,0x00,0x0F,0x80,
	0x01,0xC0,0x20,0x60,0x20,0x60,0x30,0xC0,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	't',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x04,0x00,
	0x0C,0x00,0x0C,0x00,0x7F,0x80,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
	0x0C,0x00,0x0C,0x00,0x0C,0x40,0x0C,0x40,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'u',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x10,0x40,0x71,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,0x30,0xC0,
	0x30,0xC0,0x30,0xC0,0x30,0xC0,0x39,0xE0,0x1E,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'v',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7C,0xF0,0x38,0x60,0x18,0x40,0x18,0x40,0x0C,0x80,0x0C,0x80,
	0x0C,0x80,0x07,0x00,0x07,0x00,0x07,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	'w',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xF7,0xB0,0x63,0x20,0x63,0x20,0x67,0x20,0x37,0x20,0x35,0xC0,
	0x39,0xC0,0x39,0xC0,0x39,0xC0,0x10,0x80,0x10,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

	'x',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7D,0xE0,0x18,0x80,0x19,0x80,0x0D,0x00,0x0E,0x00,0x06,0x00,
	0x07,0x00,0x0B,0x00,0x19,0x80,0x11,0xC0,0x7B,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

	'y',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7D,0xE0,0x38,0x80,0x18,0x80,0x18,0x80,0x0D,0x00,0x0D,0x00,
	0x0D,0x00,0x06,0x00,0x06,0x00,0x02,0x00,0x04,0x00,0x04,0x00,0x28,0x00,0x38,0x00,

	'z',
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3F,0xC0,0x21,0x80,0x23,0x80,0x03,0x00,0x07,0x00,0x06,0x00,
	0x0E,0x00,0x0C,0x20,0x1C,0x20,0x18,0x60,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

	'{',
	0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x80,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x01,0x00,0x03,0x00,0x04,0x00,0x03,0x00,0x01,0x00,0x01,0x00,
	0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x80,0x00,0xC0,0x00,0x00,

	'|',
	0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,
	0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,
	0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,

	'}',
	0x00,0x00,0x00,0x00,0x30,0x00,0x18,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,
	0x08,0x00,0x08,0x00,0x08,0x00,0x0C,0x00,0x02,0x00,0x0C,0x00,0x08,0x00,0x08,0x00,
	0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x18,0x00,0x30,0x00,0x00,0x00,

	'~',
	0x00,0x00,0x38,0x00,0x24,0x00,0x42,0x10,0x41,0x20,0x00,0xE0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

};

#endif