var d
label main
begin
var a
var b
var c
a = 1
b = 2
var t2
var t1
t1 = b + 2
var t0
t0 = a + 1
actual t1
actual t0
t2 = call add
c = t2
d = 999
end
label add
begin
formal x
formal y
var a
var t3
t3 = x + y
a = t3
d = a
return a
end
