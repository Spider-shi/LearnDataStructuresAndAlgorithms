#!/usr/bin/python
#-*-coding:utf-8-*-

# #  FileName    : PrintOut.py
# #  Author      : BaoBao SHI <sbbmym@icloud.com>
# #  Created     : Tue July 14 18:28 2015 by BaoBao SHI
# #  Copyright   : Feather (c) 2015
# #  Description : 递归 打印数字的每一位
# #  Time-stamp: <2015-07-14 18:30>


def PrintOut(num):
	if(num >= 10):
		PrintOut(num/10)
	
	print num % 10

if __name__ == "__main__":
	PrintOut(765432)
