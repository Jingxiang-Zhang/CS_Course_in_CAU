TaxRate=[3,10,20,25,30,35]
TaxLimit=[1500,4500,9000,35000,55000]
a=int(input())-3500
if a<=0:
    print(0)
else:
    for i in range(5):
        if TaxLimit[i]>a:
            break
    print("{}".format(int(TaxRate[i]/100*a)))

'''
TaxRate=[3,10,20,25,30,35]
TaxLimit=[1500,3000,4500,26000,20000]
a=int(input())-3500
sumTax=0
for i in range(5):
    t= TaxLimit[i] if a>TaxLimit[i] else a
    if t<0:
        break
    sumTax+=TaxRate[i]*t/100
    a-=TaxLimit[i]
    if a <=0:
        break
if i==4 and a>0:
    sumTax+=TaxRate[5]*a/100
    
print(sumTax)
'''

