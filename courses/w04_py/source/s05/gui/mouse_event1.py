
args =(5,6,2)
mystr = """line {}
line {}
line {}
""".format(*args)

print(mystr)

dic_args = {"orage":1, "apple":5, "banana":8}

mystrdic = """line {orage}
line {apple}
line {banana}
""".format(**dic_args)

print(mystrdic)
