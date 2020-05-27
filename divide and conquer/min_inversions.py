import sys
import math
import random

def get_number_of_inversions(arr, temp_arr, left, right): 
	inv_count = 0
	if left < right: 
		mid = (left + right)//2
		inv_count += get_number_of_inversions(arr, temp_arr, left, mid) 
		inv_count += get_number_of_inversions(arr, temp_arr, mid + 1, right) 
		inv_count += merge(arr, temp_arr, left, mid, right) 
	return inv_count 

def merge(arr, temp_arr, left, mid, right): 
	i = left	 # Starting index of left subarray 
	j = mid + 1 # Starting index of right subarray 
	k = left	 # Starting index of to be sorted subarray 
	inv_count = 0
	while i <= mid and j <= right: 
		if arr[i] <= arr[j]: 
			temp_arr[k] = arr[i] 
			k += 1
			i += 1
		else: 
			temp_arr[k] = arr[j] 
			inv_count += (mid-i + 1) 
			k += 1
			j += 1
	while i <= mid: 
		temp_arr[k] = arr[i] 
		k += 1
		i += 1
	while j <= right: 
		temp_arr[k] = arr[j] 
		k += 1
		j += 1
	for loop_var in range(left, right + 1): 
		arr[loop_var] = temp_arr[loop_var] 
		
	return inv_count 



 
def brute(a):
    count=0
    for i in range(len(a)-1):
        for j in range(i+1,len(a)):
            if a[j]<a[i]:
                count=count+1
    return count
if __name__ == '__main__':
    #n = int(input())
    #b=[0]*n
    #a = list(map(int, input().split()))
    flag=True
    while flag:
        n=random.randint(1,10)
        print(n)
        a=[]
        for i in range(n):
            a.append(random.randint(1,1000)%10)
        print(a)  
        b=a[:]
        v=[0]*n
        p=get_number_of_inversions(a,v, 0, len(a)-1)
        q=brute(b)
        if p!=q:
            print(a)
            print(b)
            print("Error")
            flag=False
            print(p)
            print(q)
    #print(get_number_of_inversions(a,b, 0, len(a)-1))


