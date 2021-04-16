
list_ = [i*j for i in range(2,10) for j in range(1,10)]
print(list_)
print('[i*j for i in range(2,10) for j in range(1,10)]')

list_ = [i*j for i in range(2,10) for j in range(1,10) if (i*j)%2 == 0]
print(list_)
print('[i*j for i in range(2,10) for j in range(1,10) if (i*j)%2 == 0]')

list_ = [i*j if (i*j)%2 else 0 for i in range(2,10) for j in range(1,10)]
print(list_)
print('[i*j if (i*j)%2 else 0 for i in range(2,10) for j in range(1,10)]')

list_ = [[i*j for i in range(2,10)] for j in range(1,10)]
print(list_)
print('[[i*j for i in range(2,10)] for j in range(1,10)]')

list_ = [[i*j for i in range(1,10)] for j in range(2,10)]
print(list_)
print('[[i*j for i in range(1,10)] for j in range(2,10)]')

# print('\a')

