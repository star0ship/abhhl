	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# var r

	# array l

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# var d

	# var e

	# pointer p

	# array k

	# b = 1
	LOD R5,1

	# c = b
	STO (R2+12),R5

	# c = 2
	LOD R6,2

	# var t0

	# t0 = b * c
	LOD R5,(R2+12)
	MUL R5,R6

	# a = t0
	STO (R2+72),R5

	# var t1

	# t1 = &b
	LOD R7,(R2+12)
	LOD R7,R2+12

	# p = t1
	STO (R2+76),R7

	# var t2

	# t2 = *p
	STO (R2+28),R7
	LOD R7,R2+28
	LOD R7,(R7)

	# var t3

	# t3 = t2 + 1
	STO (R2+80),R7
	LOD R8,1
	ADD R7,R8

	# b = t3
	STO (R2+84),R7

	# var t4

	# t4 = b + c
	STO (R2+12),R7
	ADD R7,R6

	# d = t4
	STO (R2+88),R7

	# var t5

	# actual c
	STO (R2+16),R6
	STO (R2+96),R6

	# actual b
	LOD R9,(R2+12)
	STO (R2+100),R9

	# t5 = call add
	STO (R2+8),R5
	STO (R2+20),R7
	STO (R2+104),R2
	LOD R4,R1+32
	STO (R2+108),R4
	LOD R2,R2+104
	JMP add

	# d = t5
	LOD R5,R4

	# var t6

	# t6 = b * c
	LOD R6,(R2+12)
	LOD R7,(R2+16)
	MUL R6,R7

	# var t7

	# t7 = t6 + d
	STO (R2+96),R6
	ADD R6,R5

	# a = t7
	STO (R2+100),R6

	# ifz a goto L1
	STO (R2+20),R5
	STO (R2+8),R6
	TST R6
	JEZ L1

	# var t8

	# t8 = b * c
	LOD R8,(R2+12)
	MUL R8,R7

	# a = t8
	STO (R2+104),R8

	# label L1
	STO (R2+8),R8
L1:

	# d = 999
	LOD R5,999

	# var t9

	# t9 = b - 1
	LOD R6,(R2+12)
	LOD R7,1
	SUB R6,R7

	# k[t9] = 1
	LOD R8,(R2+32)
	MUL R6,4
	ADD R8,R6
	LOD R9,1
	STO (R8),R9

	# var t10

	# t10 = b - 1
	LOD R10,(R2+12)
	LOD R11,1
	SUB R10,R11

	# var t11

	# t11 = k[t10]
	MUL R10,4
	ADD R8,R10
	LOD R8,(R8)
	# l[t11] = 97
	LOD R4,STATIC
	LOD R12,(R4+4)
	MUL R8,4
	ADD R12,R8
	LOD R13,97
	STO (R12),R13

	# actual d
	STO (R2+20),R5
	STO (R2+120),R5

	# call PRINTN
	STO (R2+108),R6
	STO (R2+116),R8
	STO (R2+112),R10
	STO (R2+124),R2
	LOD R4,R1+32
	STO (R2+128),R4
	LOD R2,R2+124
	JMP PRINTN

	# actual 10
	LOD R5,10
	STO (R2+120),R5

	# call PRINTN
	STO (R2+124),R2
	LOD R4,R1+32
	STO (R2+128),R4
	LOD R2,R2+124
	JMP PRINTN

	# var t12

	# t12 = l[1]
	LOD R4,STATIC
	LOD R5,(R4+4)
	LOD R6,1
	MUL R6,4
	ADD R5,R6
	LOD R5,(R5)
	# actual t12
	STO (R2+120),R5
	STO (R2+124),R5

	# call PRINTN
	STO (R2+128),R2
	LOD R4,R1+32
	STO (R2+132),R4
	LOD R2,R2+128
	JMP PRINTN

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# label add
add:

	# begin

	# formal x

	# formal y

	# var z

	# var t13

	# t13 = x + y
	LOD R5,(R2-4)
	LOD R6,(R2-8)
	ADD R5,R6

	# z = t13
	STO (R2+12),R5

	# return z
	LOD R4,R5
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

PRINTN:
	LOD R7,(R2-4) # 789
	LOD R15,R7 # 789 
	DIV R7,10 # 78
	TST R7
	JEZ PRINTDIGIT
	LOD R8,R7 # 78
	MUL R8,10 # 780
	SUB R15,R8 # 9
	STO (R2+8),R15 # local 9 store

	# out 78
	STO (R2+12),R7 # actual 78 push

	# call PRINTN
	STO (R2+16),R2
	LOD R4,R1+32
	STO (R2+20),R4
	LOD R2,R2+16
	JMP PRINTN

	# out 9
	LOD R15,(R2+8) # local 9 

PRINTDIGIT:
	ADD  R15,48
	OUT

	# ret
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

PRINTS:
	LOD R7,(R2-4)

PRINTC:
	LOD R15,(R7)
	DIV R15,16777216
	TST R15
	JEZ PRINTSEND
	OUT
	ADD R7,1
	JMP PRINTC

PRINTSEND:
	# ret
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

EXIT:
	END

STATIC:
	DBN 0,44
STACK: