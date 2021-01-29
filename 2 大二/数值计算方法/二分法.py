import math
def fun(n):
    return 1-n*math.log(n,math.e)
begin=0.5
end=4
mid=(end-begin)/2
fu=fun(mid)
fub=0
mids=begin
flag=fun(mids)
mide=end
while math.fabs(mids-mide)>0.0001 and math.fabs(fu-fub)>0.0001:
    fub=fu
    flag=fun(mids)
    midb=mid
    if flag*fu<0:
        mide=mid
    if flag*fu>0:
        mids=mid
    mid=(mide-mids)/2+mids
    fu=fun(mid)
print("{:.3f}".format(mid))
    
