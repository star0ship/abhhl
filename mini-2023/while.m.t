label main
begin
var i
i = 1
label L1
var t0
t0 = (i < 10)
ifz t0 goto L2
var t1
t1 = i + 1
i = t1
goto L1
label L2
i = 999
end
