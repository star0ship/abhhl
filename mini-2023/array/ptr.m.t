	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# var d

	# var e

	# pointer p

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
	STO (R2+32),R5

	# var t1

	# t1 = &b
	LOD R7,(R2+12)
	LOD R7,R2+12

	# p = t1
	STO (R2+36),R7

	# var t2

	# t2 = c + 1
	STO (R2+16),R6
	LOD R8,1
	ADD R6,R8

	# *p = t2
	STO (R2+28),R7
	LOD R7,R2+28
	LOD R7,(R7)
	ADD R7,R2
	STO (R7),R6

	# var t3

	# t3 = *p
	LOD R6,(R2+28)
	LOD R6,R2+28
	LOD R6,(R6)

	# var t4

	# t4 = t3 + 1
	STO (R2+44),R6
	LOD R7,1
	ADD R6,R7

	# b = t4
	STO (R2+48),R6

	# var t5

	# t5 = b + c
	STO (R2+12),R6
	LOD R9,(R2+16)
	ADD R6,R9

	# d = t5
	STO (R2+52),R6

	# var t6

	# actual c
	STO (R2+60),R9

	# actual b
	LOD R10,(R2+12)
	STO (R2+64),R10

	# t6 = call add
	STO (R2+8),R5
	STO (R2+20),R6
	STO (R2+68),R2
	LOD R4,R1+32
	STO (R2+72),R4
	LOD R2,R2+68
	JMP add

	# d = t6
	LOD R5,R4

	# var t7

	# t7 = b * c
	LOD R6,(R2+12)
	LOD R7,(R2+16)
	MUL R6,R7

	# var t8

	# t8 = t7 + d
	STO (R2+60),R6
	ADD R6,R5

	# a = t8
	STO (R2+64),R6

	# d = 999
	LOD R8,999

	# actual d
	STO (R2+20),R8
	STO (R2+68),R8

	# call PRINTN
	STO (R2+8),R6
	STO (R2+72),R2
	LOD R4,R1+32
	STO (R2+76),R4
	LOD R2,R2+72
	JMP PRINTN

	# actual p
	LOD R5,(R2+28)
	STO (R2+68),R5

	# call zero
	STO (R2+72),R2
	LOD R4,R1+32
	STO (R2+76),R4
	LOD R2,R2+72
	JMP zero

	# actual b
	LOD R5,(R2+12)
	STO (R2+68),R5

	# call PRINTN
	STO (R2+72),R2
	LOD R4,R1+32
	STO (R2+76),R4
	LOD R2,R2+72
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

	# var t9

	# t9 = x + y
	LOD R5,(R2-4)
	LOD R6,(R2-8)
	ADD R5,R6

	# z = t9
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

	# label zero
zero:

	# begin

	# formal ptr

	# *ptr = 0
	LOD R5,(R2-4)
	LOD R6,0
	LOD R5,R4+-4
	LOD R5,(R5)
	ADD R5,R4
	STO (R5),R6

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
	DBN 0,0
STACK: