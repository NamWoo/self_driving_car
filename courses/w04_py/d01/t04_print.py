name="NAMWOO"
age=20
height=160.9

print("name:{2}, age:{0}, height:{2}".format(name, age, height))

print("name:{name}, age:{age}, height:{height}".format(name="NAMWOO", age=20, height=160.9))

boy={"name":"NAMWOO", "age":20, "height":160.9}
print("name:{0[name]}, age:{0[age]}, height:{0[height]}".format(boy))

print("name:{0:s}, age:{1:d}, height:{2:f}".format(name, age, height))



print("name:{0:10s}, age:{1:5d}, height:{2:8.2f}".format(name, age, height))



print("name:{0:^10s}, age:{1:>5d}, height:{2:<8.2f}".format(name, age, height))



print("name:{0:$^10s}, age:{1:>05d}, height:{2:!<8.2f}".format(name, age, height))
