
***20190605 마지막업데이트***

# Python


## 괄호명칭 정리
여기도 ... 정말... 도대체 몇번을 정리해놨는지.. 또 까먹었다.. 제발 기억하자.  [출처](https://zetawiki.com/wiki/%EA%B4%84%ED%98%B8)

|이름|열기|닫기|영어명칭|용도|
|:------:|:------:|:------:|:------:|:------:|
|소괄호, 괄호, 손톱괄호, 손톱묶음|(|)|parentheses|수학 소괄호
|겹소괄호, 이중소괄호|⦅|⦆|double parentheses|
|중괄호|{|}|braces, curly brackets|수학 중괄호
|대괄호, 꺾쇠|[|]|brakets, square brackets|수학 대괄호
	
자 다시 잘 기억하자.
* 가장 기본 `(  )` ***parentheses***
* 컬리!! 꼬불들어갔으니 `{  }` ***curly***
* 각졌으니 `[ ]` ***square***

괄호 했으니 이제 따옴표 이름도 다시!

* quotation marks, inverted commas, quotes, speech marks
  * 따옴표, 인용 부호, 인용부, ***쿼츠***
  * 쿠오테이션!!
* double quotes
  * 큰따옴표, 쌍따옴표, 겹따옴표, ***더블 쿼츠***
  * `"  "`
* single quotes
  * 작은따옴표, 홑따옴표, ***싱글 쿼츠***
  * `'  '`


## print 

그 사이 까먹은 print.. 다시 정리

* python 2.6 이후 나온 신형 포멧팅
* 여기 내용 정말 자주 찾아서 사용하던 건데.. 또 정리한다.
* 도대체 몇번을 정리하는지 모르겠지만..
* 매번 사용할 때마다 검색을...... 이제 그만.. 검색하고 기억 좀 하자. [출처참고](https://books.google.co.kr/books?id=YrpUDwAAQBAJ&pg=PA193&lpg=PA193&dq=%ED%8C%8C%EC%9D%B4%EC%8D%AC+%EA%B4%84%ED%98%B8+%EC%9D%B4%EB%A6%84&source=bl&ots=YsjDmj0z4F&sig=ACfU3U3uEy7PXKQLSS33RHMKH73kzNvu0w&hl=en&sa=X&ved=2ahUKEwjK6OL82MziAhWMzIsBHdyiC6cQ6AEwBXoECAkQAQ)
```python
//서식지정자
>>>x=100
>>>"x is %s" %x
'x is 100'

//여러 객체 서식문자에 전달
>>>'%d + %d = %d' % (3, 7, 10)
'3 + 7 = 10'


print("이름:{2}, 나이:{0}, 키:{2}".format(name, age, height))   
//안에 숫자 안넣으면 자동으로 순서대로 설정
//name:181.5, age:NAMWOO, height:181.5


print("이름:{name}, 나이:{age}, 키:{height}".format(name="나무", age=20, height=181.5))   
//요로코롬 하면 순서도 상관없이 할 수 있는
//name:NAMWOO, age:20, height:181.5


//사전에 저장된 값을 출력할 때
boy={"name":"나무", "age":20, "height":181.5}
print("이름:{0[name]}, 나이:{0[age]}, 키:{0[height]}".format(boy))
//name:NAMWOO, age:20, height:181.5


//문자열 s //정수는 d //실수는 f
name="나무"
age=20
height=181.5
print("이름:{0:s}, 나이:{1:d}, 키:{2:f}".format(name, age, height))
//name:NAMWOO, age:20, height:181.500000


//폭과 정밀도 까지 
name="나무"
age=20
height=181.5
print("이름:{0:10s}, 나이:{1:5d}, 키:{2:8.2f}".format(name, age, height))
//name:NAMWOO    , age:   20, height:  181.50


//별다른 정렬 지정이 없으면 문자열은 왼쪽으로 정렬되고 수치값은 오른쪽으로 정렬
//정렬지정할 때 <왼쪽 >오른쪽 ^중앙
name="나무"
age=20
height=181.5
print("이름:{0:^10s}, 나이:{1:>5d}, 키:{2:<8.2f}".format(name, age, height))
//name:  NAMWOO  , age:   20, height:181.50  


//거기다 중앙정렬도 가능
//채움문자를 지정하면 공백대신 채움문자 출력
name="나무"
age=20
height=181.5
print("이름:{0:$^10s}, 나이:{1:>05d}, 키:{2:!<8.2f}".format(name, age, height))
//name:$$NAMWOO$$, age:00020, height:181.50!!
```

디버그 단축키
* `Ctrl + Shift + D` Python 디버거 세팅
* `F9` 디버 포인터 설정
* `F5` 디버깅








## input 문제1


`input` 자료구조에 대한 강의를 보는데 해당 강의가 python 2.대 다보니 얄팍한 지식이 더욱 헷갈리기에 정리하려 한다. 아래처럼 했더니 오류가 났기 때문에.. 기억에 저편에서 해결과정을 더 쉽게 꺼내기 위해..




### 문제점 

```python
class HelloWorld:
    def __init__(self):
        print("Hello World, just one more time")
    def __del__(self):
        print("Good Bye")
    def performAverage(self, val1, val2):
        average = (val1+val2) / 2.0
        print("The average of the scores is : {} ".format(average))

def main():
    world = HelloWorld()
    score1, score2 = input("Enter two scores separated by a comma: ")
    world.performAverage(score1, score2)

main()    
```

이렇게 하면 입력이 안된다. 
* `1, 2`
* `1 2`
* `1. 2`
그러니까 이렇게 입력하면 

```
Hello World, just one more time
Enter two scores separated by a comma: 1, 2
ValueError: too many values to unpack (expected 2)
Good Bye
```
1과 2로 입력이 나눠지지 않는 오류가 python 3.대로 와서 바뀐건지 안되고 있다.

이럴땐 아래와 같이 해결.


## 해결

[출처](https://www.geeksforgeeks.org/taking-multiple-inputs-from-user-in-python/)

### split() method

`input().split(separator, maxsplit)`

```python
def main1():
    # Python program showing how to 
    # multiple input using split 
    
    # taking two inputs at a time 
    x, y = input("Enter a two value: ").split() 
    print("Number of boys: ", x) 
    print("Number of girls: ", y) 
    print() 
    
    # taking three inputs at a time 
    x, y, z = input("Enter a three value: ").split() 
    print("Total number of students: ", x) 
    print("Number of boys is : ", y) 
    print("Number of girls is : ", z) 
    print() 
    
    # taking two inputs at a time 
    a, b = input("Enter a two value: ").split() 
    print("First number is {} and second number is {}".format(a, b)) 
    print() 
    
    # taking multiple inputs at a time  
    # and type casting using list() function 
    x = list(map(int, input("Enter a multiple value: ").split())) 
    print("List of students: ", x) 
```
![](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Capture8-1.png)

무적에 `split()` 이건 정말 어디서든 튀어나와서 문제를 해결해주는!



### List comprehension

```python
# Python program showing 
# how to take multiple input 
# using List comprehension 
  
# taking two input at a time 
x, y = [int(x) for x in input("Enter two value: ").split()] 
print("First Number is: ", x) 
print("Second Number is: ", y) 
print() 
  
# taking three input at a time 
x, y, z = [int(x) for x in input("Enter three value: ").split()] 
print("First Number is: ", x) 
print("Second Number is: ", y) 
print("Third Number is: ", z) 
print() 
  
# taking two inputs at a time 
x, y = [int(x) for x in input("Enter two value: ").split()] 
print("First number is {} and second number is {}".format(x, y)) 
print() 
  
# taking multiple inputs at a time  
x = [int(x) for x in input("Enter multiple value: ").split()] 
print("Number of list is: ", x)  
```

![](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Capture9-1.png)









---

[다시 # week 4 index 로](../w04.md)

[다시 # 전 과정 main 으로](../../README.md)
