                       
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
