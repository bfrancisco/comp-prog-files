import time

num = 10**7
list_ = [i for i in range(num)]
set_ = set(list_)
dict_ = {i:0 for i in range(num)}

# start time
st = time.time()

# List operations
print(list_[0])         # element access by index, O(1)
list_.append(1)         # O(1)
list_.pop(0)            # O(n)
if num - 1 in list_:    # O(n), worst case
    print('in list')

# Set operations
set_.add(1)             # O(1)
set_.remove(num - 1)    # O(1)
if num - 1 in set_:     # O(1)
    print('in set')
# cannot access specific element in a set. no duplicates!

# Dictionary operations
print(dict_[1])         # element access by key, O(1)
dict_[1] = 1            # O(1)
dict_.pop(1)            # O(1)
if num - 1 in dict_:    # O(1)
    print('in dict')


# end time
et = time.time()

# get the execution time
elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')