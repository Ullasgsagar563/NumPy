# NumPy
implimentig some of numpy array methods using c++ and templet
this project show how genric progaramming can be usefull

# run and test
ullas@ULLAS:~/CC_E4_PES1UG22CS844/gpro/NumPy$ g++ main.cpp -std=c++17<br>
ullas@ULLAS:~/CC_E4_PES1UG22CS844/gpro/NumPy$ ./a.out<br>
Enter command: a=[1,2,3]<br>
Array a created.<br>
Enter command: print(a)<br>
a = [1, 2, 3]<br>
Enter command: b=[1.1,1.2] <br>          
Array b created.<br>
Enter command: print(b)<br>
b = [1.1, 1.2]<br>
Enter command: c=["1","q"]<br>
Array c created.<br>
Enter command: print(c)<br>
c = ["1", "q"]<br>
Enter command: d=["ab]<br>
Array d created.<br>
Enter command: print(d)<br>
d = ["ab]<br>
Enter command: a.size<br>
Size of a: 3<br>
Enter command: a.max<br>
Maximum value in array a: 3<br>
Enter command: a.sum<br>
Sum of elements in array a: 6<br>
Enter command: a.min<br>
Minimum value in array a: 1<br>
Enter command: a[1]<br>
Element at index 1 in array a: 2<br>
Enter command: a[2]<br>
Element at index 2 in array a: 3<br>
Enter command: <br>

![alt text](image.png)

#phase 2
![alt text](image-1.png)

output:

<code>ullas@ULLAS:~/gpro/NumPy$ g++ main.cpp -std=c++17
ullas@ULLAS:~/gpro/NumPy$ ./a.out
>>>a=[1,2,3,4]
Array a created.
>>>print(a)
a = [1, 2, 3, 4]
>>>b=[1.1,1.2,1.3]
Array b created.
>>>c=["runtime",terror"]
Array c created.
>>>a.size
4
>>>b.size
3
>>>c.size
2
>>>a[1]
2
>>>a[2]
3
>>>b[1]
1.2
>>>c[1]
terror"
>>>a.max
4
>>>a.min
1
>>>a.sum 
10
>>>exit
ullas@ULLAS:~/gpro/NumPy$ </code>
![alt text](image-2.png)