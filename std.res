size of first: 0
size of second: 3
size of third: 0
size of fourth: 2
a and b are equal
b and c are not equal
b is less than c
c is greater than b
a is less than or equal to b
a is greater than or equal to b
                       
[36m
***************	 TEST INSERT		*****************
[0m
bar
truc
machin
foo
salut
Marcel
                       
[36m
***************	 TEST ERASE		*****************
[0m
found b
erase iterator to b
erase by key 'c'
erase by range 'e' to end
 display :
a => 10
d => 40
                       
[36m
***************	 TEST ITERATORS		*****************
[0m
a => 200
b => 100
c => 300
Hello there
a => 200
b => 100
c => 300
General Kenobi
Wupwup
marker1
Trump is a kiddo
a => 200
b => 100
c => 300
                       
[36m
***************	 TEST ASSIGNATION	*****************
[0m
assigned 'a'
assiged 'c'
assigned 'f'
end of assignations
a is an element of map.
b is not an element of map.
c is an element of map.
d is not an element of map.
e is not an element of map.
f is an element of map.
g is not an element of map.
[36m
**************      TEST VALUECOMP/KEYCOMP   ****************** 
[0m
comparing 3 to 2 
[36m3 is not inferior to 2[0m
comparing pair ('a', 2) to pair ('b', 4) 
[36mpair ('a', 2) is inferior to pair ('b' , 4)[0m
[36m
**************      TEST EMPTY   ****************** 
[0m
that container is not empty
[36m
**************      TEST RELATIONAL OPERATORS   ****************** 
[0m
foo and bar are not equal
foo is greater than bar
foo is greater than or equal to bar
[36m
**************      TEST OPERATOR[]   ****************** 
[0m
themap['a'] is an element
themap['b'] is another element
themap['c'] is another element
themap['d'] is 
themap now contains 4 elements.
[36m
**************      TEST OPERATOR=   ****************** 
[0m
Size of first: 0
Size of second: 3
[36m
**************      TEST LOWER_BOUND   ****************** 
[0m
low : b
up : e
a => 20
e => 100
[36m
**************      TEST EQUAL RANGE   ****************** 
[0m
lower bound points to: b => 20
upper bound points to: c => 30
[36m
**************      TEST SWAP   ****************** 
[0m
foo contains:
x => 100
y => 200
bar contains:
a => 11
b => 22
c => 33
foo contains:
a => 11
b => 22
c => 33
bar contains:
x => 100
y => 200
foo contains:
a => 11
b => 22
c => 33
bar contains:
x => 100
y => 200
x => 100
y => 200
a => 11
b => 22
c => 33
11 22 33 
73 173 763 73854 74683 753 
100 200 
y => 200
x => 100
c => 33
b => 22
a => 11
1 => 73
2 => 173
3 => 763
4 => 73854
5 => 74683
6 => 753
11 22 33 
100 200 
73 173 763 73854 74683 753 
x => 100
y => 200
a => 11
b => 22
c => 33
6 => 753
5 => 74683
4 => 73854
3 => 763
2 => 173
1 => 73
mymap size before clear is 5
mymap size after clear is 0
[45;1m************** TEST CONSTRUCTOR ****************[0m
ok
ok
4
 100
 100
 100

ok
 100 100 100
[45;1m************** TEST CAPACITY ****************[0m
size: 204
capacity: 256
max_size: 2305843009213693951
size: 203
size: 0
[45;1m************** TEST RESIZE ****************[0m
9
 1 2 3 4 5 6 7 8 9
5
8
end :0
[45;1m************** TEST ELEMENT ACCESS ****************[0m
myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
front: 1
back : 0
[45;1m************** MODIFIERS ****************[0m
[36m**************  INSERT ****************[0m
my vector   : 1 2 3 4 5 100 100 100 0 0 0 0
new_content : 4 1 2 3 4 5 100 100 100 0 0 0 0
my vector   : 2 2 2
new_content : 6 6 6 6 6 2 2 2
my vector   : 8 8 8 8 8
new_content caca: 6 6 6 6 6 2 2 2 8 8 8 8 8
[36m**************  ERASE ****************[0m
 0 1 2 3 4 5 6 7 8 9
 0 1 2 3 5 6 7 8 9
 8 9
[36m**************  ASSIGN ****************[0m
Size of first: 7
Size of second: 5
Size of third: 3
[36m**************  SWAP  ****************[0m
foo contains: 200 200 200 200 200
bar contains: 100 100 100
[36m**************  OPERATOR=  ****************[0m
Size of jet: 0
Size of li : 3
[45;1m************** NON MEMBER FONCTION OVERLOADS ****************[0m
[36m**************  RELATIONAL OPERATOR==  ****************[0m
foo and bar are not equal
foo is less than bar
foo is less than or equal to bar
