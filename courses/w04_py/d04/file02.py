path = "C:\\Users\\fyj\\nw\\self_driving_car-master\\courses\\w04_py\\d04\\"

def my_readwrite1():
    f = open(path + "Testfile1.txt", 'r')

    for line in f:                # 파일 객체 줄 단위로 항목이 순회
        print(line, end="")  # == print(line.strip()) 
    else:
        print('\n')
        
    f.seek(0.0)
    print(f.readlines())    # 파일의 내용을 리스트로 반환
    f.close()

def my_readwrite2():
    f = open(path + "Testfile1.txt", 'r+')
    print(f.read())                          # 파일 내용 전체 읽기
    print(f.tell())                           # 현재 파일 포인터 위치 출력
    f.seek(10,0)                              # 파일 포인터 위치를 맨 앞으로 이동

    f.write("c/c++")                      # 현재 위치에 “c/c++”문자열 저장
    f.flush()                                  # 쓰기 버퍼 비워주는 동작(실제 파일에 저장
    f.seek(0,0)
    print(f.read())
    f.close()




# my_readwrite1(); print("")

my_readwrite2()