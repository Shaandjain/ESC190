def change_a(p_a):
    p_a[0] = 10

aa = [5]
change_a(aa)
print(aa[0])

#differences: uses list values to store memory address, so when you change the value of the list, you change the value of the memory address
#contrary to C, where we assign a pointer to a memory address, and then change the value of the memory address