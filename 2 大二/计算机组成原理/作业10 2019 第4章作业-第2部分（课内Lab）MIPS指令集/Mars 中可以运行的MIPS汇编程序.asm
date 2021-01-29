.data
var1:  .word  23  # declare storage for var1;
#initial value is 23
.text
__start:
lw  $t0, var1  # load contents of RAM location
# into register $t0:
# $t0 = var1
li  $t1, 5 # $t1 = 5 ("load immediate")
sw  $t1, var1  # store contents of register $t1
# into RAM: var1 = $t1 done
 