	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var i

	# var a

	# a = 0
	LOD R5,0

	# i = 0
	LOD R6,0

	# label L1
	STO (R2+12),R5
	STO (R2+8),R6
L1:

	# var t0

	# t0 = (i <= 5)
	LOD R5,(R2+8)
	LOD R6,5
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,1
	LOD R3,R1+24
	JMP R3
	LOD R5,0

	# ifz t0 goto L2
	STO (R2+16),R5
	TST R5
	JEZ L2

	# var t2

	# t2 = a + i
	LOD R7,(R2+12)
	LOD R8,(R2+8)
	ADD R7,R8

	# a = t2
	STO (R2+20),R7

	# var t1

	# t1 = i + 2
	LOD R9,2
	ADD R8,R9

	# i = t1
	STO (R2+24),R8

	# goto L1
	STO (R2+12),R7
	STO (R2+8),R8
	JMP L1

	# label L2
L2:

	# return 0
	LOD R4,0
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
	DBN 0,0
STACK:
