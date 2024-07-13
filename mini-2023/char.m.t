type :7
label main
begin
char a
a = 97
actual L1
call PRINTS
actual a
call PRINTN
actual L2
call PRINTS
var t0
t0 = a + 1
a = t0
actual L3
call PRINTS
actual a
call PRINTN
actual L2
call PRINTS
end
	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# char a

	# a = 97
	LOD R5,97

	# actual L1
	LOD R6,L1
	STO (R2+12),R6

	# call PRINTS
	STO (R2+8),R5
	STO (R2+16),R2
	LOD R4,R1+32
	STO (R2+20),R4
	LOD R2,R2+16
	JMP PRINTS

	# actual a
	LOD R5,(R2+8)
	STO (R2+12),R5

	# call PRINTN
	STO (R2+16),R2
	LOD R4,R1+32
	STO (R2+20),R4
	LOD R2,R2+16
	JMP PRINTN

	# actual L2
	LOD R5,L2
	STO (R2+12),R5

	# call PRINTS
	STO (R2+16),R2
	LOD R4,R1+32
	STO (R2+20),R4
	LOD R2,R2+16
	JMP PRINTS

	# var t0

	# t0 = a + 1
	LOD R5,(R2+8)
	LOD R6,1
	ADD R5,R6

	# a = t0
	STO (R2+12),R5

	# actual L3
	LOD R7,L3
	STO (R2+16),R7

	# call PRINTS
	STO (R2+8),R5
	STO (R2+20),R2
	LOD R4,R1+32
	STO (R2+24),R4
	LOD R2,R2+20
	JMP PRINTS

	# actual a
	LOD R5,(R2+8)
	STO (R2+16),R5

	# call PRINTN
	STO (R2+20),R2
	LOD R4,R1+32
	STO (R2+24),R4
	LOD R2,R2+20
	JMP PRINTN

	# actual L2
	LOD R5,L2
	STO (R2+16),R5

	# call PRINTS
	STO (R2+20),R2
	LOD R4,R1+32
	STO (R2+24),R4
	LOD R2,R2+20
	JMP PRINTS

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

L3:
	DBS 97,49,58,32,0
L2:
	DBS 10,0
L1:
	DBS 97,58,32,0
STATIC:
	DBN 0,0
STACK:
