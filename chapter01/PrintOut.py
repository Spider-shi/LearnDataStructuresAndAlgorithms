#!/usr/bin/env python
#-*-coding:utf-8-*-

#递归函数
#依次打印数字的每一位

def PrintOut(num):
	if(num >= 10):
		PrintOut(num/10)
	
	print num % 10

if __name__ == "__main__":
	PrintOut(765432)
