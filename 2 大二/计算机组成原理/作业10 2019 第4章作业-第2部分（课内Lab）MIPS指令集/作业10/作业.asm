#int pof2[6] ={ 1，2，8，4，16，10 } 中找到最大值，并记录。
.data
array: .space 24

.text
main:
#首先进行数组的赋值
la $t0,array #将array的地址装入t0寄存器中         t0
li $t1,1     #将1装入t1寄存器临时储存              t1
sw $t1,($t0) #将t1寄存器的值放入到array地址中
li $t1,2
sw $t1,4($t0)
li $t1,8
sw $t1,8($t0)
li $t1,4
sw $t1,12($t0)
li $t1,16
sw $t1,16($t0)
li $t1,10
sw $t1,20($t0)

li $t5,6 #i=6                                   t5
li $t6,1#j=1                                    t6
li $t9,-10# t9表示即将记录的最大值max value     t9
while:    #while(true)
sub $t5,$t5,$t6 #i=i-j=i-1
sll $t4,$t5,2 #address offset = i*4             t4
add $t7,$t4,$t0 #将偏移量加基地址找到对应的地址 t7
lw $t8,($t7)  #将对应的地址内容装入到t8中       t8

slt $t3,$t9,$t8   #将t8得到的数与t9 max比较，     t3
#if ($9 < $8) $3=1; else $3=0，结果存入t3中
beq $t3,$zero,done #如果比较结果为0，也就是s9>s7，
#最大值max已经比s7大，则直接跳过赋值
move $t9,$t8
done:

beq $t5,$zero,finish #if(i==0) goto finish
beq $zero,$zero,while #else goto while

finish:    #while 结束
li  $v0,1
move  $a0,$t9
syscall
#最后结果存储在t9，a0寄存器中

