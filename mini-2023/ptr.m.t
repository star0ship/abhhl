label main
begin
var a
var b
var c
var d
var e
pointer p
b = 1
c = 2
var t0
t0 = &a
p = t0
var t1
t1 = c + 1
*p = t1
actual L1
call PRINTS
actual a
call PRINTN
actual L2
call PRINTS
actual p
call add1
actual L3
call PRINTS
actual a
call PRINTN
actual L2
call PRINTS
var t2
t2 = *p
var t3
t3 = t2 + 2
b = t3
actual L4
call PRINTS
actual b
call PRINTN
actual L2
call PRINTS
end
label add1
begin
formal ptr
var t4
t4 = *ptr
var t5
t5 = t4 + 1
*ptr = t5
end
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

	# c = 2
	LOD R6,2

	# var t0

	# t0 = &a
	LOD R7,(R2+8)
	LOD R7,R2+8

	# p = t0
	STO (R2+32),R7

	# var t1

	# t1 = c + 1
	STO (R2+16),R6
	LOD R8,1
	ADD R6,R8

	# *p = t1
	STO (R2+28),R7
	LOD R7,R2+28
	LOD R7,(R7)
	STO (R7),R6

	# actual L1
	LOD R6,L1
	STO (R2+40),R6

	# call PRINTS
	STO (R2+12),R5
	STO (R2+44),R2
	LOD R4,R1+32
	STO (R2+48),R4
	LOD R2,R2+44
	JMP PRINTS

	# actual a
	LOD R5,(R2+8)
	STO (R2+40),R5

	# call PRINTN
	STO (R2+44),R2
	LOD R4,R1+32
	STO (R2+48),R4
	LOD R2,R2+44
	JMP PRINTN

	# actual L2
	LOD R5,L2
	STO (R2+40),R5

	# call PRINTS
	STO (R2+44),R2
	LOD R4,R1+32
	STO (R2+48),R4
	LOD R2,R2+44
	JMP PRINTS

	# actual p
	LOD R5,(R2+28)
	STO (R2+40),R5

	# call add1
	STO (R2+44),R2
	LOD R4,R1+32
	STO (R2+48),R4
	LOD R2,R2+44
	JMP add1

	# actual L3
	LOD R5,L3
	STO (R2+40),R5

	# call PRINTS
	STO (R2+44),R2
	LOD R4,R1+32
	STO (R2+48),R4
	LOD R2,R2+44
	JMP PRINTS

	# actual a
	LOD R5,(R2+8)
	STO (R2+40),R5

	# call PRINTN
	STO (R2+44),R2
	LOD R4,R1+32
	STO (R2+48),R4
	LOD R2,R2+44
	JMP PRINTN

	# actual L2
	LOD R5,L2
	STO (R2+40),R5

	# call PRINTS
	STO (R2+44),R2
	LOD R4,R1+32
	STO (R2+48),R4
	LOD R2,R2+44
	JMP PRINTS

	# var t2

	# t2 = *p
	LOD R5,(R2+28)
	LOD R5,(R2+28)
	LOD R5,(R5)

	# var t3

	# t3 = t2 + 2
	STO (R2+40),R5
	LOD R6,2
	ADD R5,R6

	# b = t3
	STO (R2+44),R5

	# actual L4
	LOD R7,L4
	STO (R2+48),R7

	# call PRINTS
	STO (R2+12),R5
	STO (R2+52),R2
	LOD R4,R1+32
	STO (R2+56),R4
	LOD R2,R2+52
	JMP PRINTS

	# actual b
	LOD R5,(R2+12)
	STO (R2+48),R5

	# call PRINTN
	STO (R2+52),R2
	LOD R4,R1+32
	STO (R2+56),R4
	LOD R2,R2+52
	JMP PRINTN

	# actual L2
	LOD R5,L2
	STO (R2+48),R5

	# call PRINTS
	STO (R2+52),R2
	LOD R4,R1+32
	STO (R2+56),R4
	LOD R2,R2+52
	JMP PRINTS

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

	# label add1
add1:

	# begin

	# formal ptr

	# var t4

	# t4 = *ptr
	LOD R5,(R2-4)
	LOD R5,(R2-4)
	LOD R5,(R5)

	# var t5

	# t5 = t4 + 1
	STO (R2+8),R5
	LOD R6,1
	ADD R5,R6

	# *ptr = t5
	LOD R7,(R2-4)
	LOD R7,R2-4
	LOD R7,(R7)
	STO (R7),R5

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

L4:
	DBS 98,58,32,0
L3:
	DBS 97,50,58,32,0
L2:
	DBS 10,0
L1:
	DBS 97,49,58,32,0
STATIC:
	DBN 0,0
STACK:
