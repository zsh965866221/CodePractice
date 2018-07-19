#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Time      : 2018/3/21 9:24
# Author    : zsh_o

import re

def cal_mul(matched):
    sa = matched.group(1)
    sb = matched.group(2)
    if len(sa)>1 and sa[0] == '0' and sa[1] == '0':
        a = -float(sa)
    else:
        a = float(sa)
    if len(sb)>1 and sb[0] == '0' and sb[1] == '0':
        b = -float(sb)
    else:
        b = float(sb)
    c = a * b
    if c < 0:
        return '00' + str(-c)
    else:
        return str(c)
def cal_div(matched):
    sa = matched.group(1)
    sb = matched.group(2)
    if len(sa) > 1 and sa[0] == '0' and sa[1] == '0':
        a = -float(sa)
    else:
        a = float(sa)
    if len(sb) > 1 and sb[0] == '0' and sb[1] == '0':
        b = -float(sb)
    else:
        b = float(sb)
    c = a / b
    if c < 0:
        return '00' + str(-c)
    else:
        return str(c)
def cal_add(matched):
    sa = matched.group(1)
    sb = matched.group(2)
    if len(sa) > 1 and sa[0] == '0' and sa[1] == '0':
        a = -float(sa)
    else:
        a = float(sa)
    if len(sb) > 1 and sb[0] == '0' and sb[1] == '0':
        b = -float(sb)
    else:
        b = float(sb)
    c = a + b
    if c < 0:
        return '00' + str(-c)
    else:
        return str(c)
def cal_sub(matched):
    sa = matched.group(1)
    if sa == '':
        sa = '0'
    sb = matched.group(2)
    if len(sa) > 1 and sa[0] == '0' and sa[1] == '0':
        a = -float(sa)
    else:
        a = float(sa)
    if len(sb) > 1 and sb[0] == '0' and sb[1] == '0':
        b = -float(sb)
    else:
        b = float(sb)
    c = a - b
    if c < 0:
        return '00' + str(-c)
    else:
        return str(c)


def cal_bracket(matched):
    bracket_s = matched.group(1)
    p = bracket_s
    ## 先算除法
    st = []
    while st is not None:
        st = re.search('([0-9]+[.]{0,1}[0-9]*)\/([0-9]+[.]{0,1}[0-9]*)', p)
        p = re.sub('([0-9]+[.]{0,1}[0-9]*)\/([0-9]+[.]{0,1}[0-9]*)', cal_div, p, count=1)
    st = []
    while st is not None:
        st = re.search('([0-9]+[.]{0,1}[0-9]*)\*([0-9]+[.]{0,1}[0-9]*)', p)
        p = re.sub('([0-9]+[.]{0,1}[0-9]*)\*([0-9]+[.]{0,1}[0-9]*)', cal_mul, p, count=1)
    ## 先算负的，再算正的，防止开头是负号的情况
    st = []
    while st is not None:
        st = re.search('([0-9]*[.]{0,1}[0-9]*)\-([0-9]+[.]{0,1}[0-9]*)', p)
        p = re.sub('([0-9]*[.]{0,1}[0-9]*)\-([0-9]+[.]{0,1}[0-9]*)', cal_sub, p, count=1)
    st = []
    while st is not None:
        st = re.search('([0-9]+[.]{0,1}[0-9]*)\+([0-9]+[.]{0,1}[0-9]*)', p)
        p = re.sub('([0-9]+[.]{0,1}[0-9]*)\+([0-9]+[.]{0,1}[0-9]*)', cal_add, p, count=1)
    st = p[1:-1]
    return st

s = '1-2*((60-30+(9-2*5/3+7/3*99/4*2998+10*2998+10*568/14))-(-4*3)/(16-3*2))'
# s = '1-2'
p = s
st = []
while st is not None:
    st = re.search('(\([^\(\)]+\))', p)
    p = re.sub('(\([^\(\)]+\))', cal_bracket, p)

def cal_final(final_s):
    p = final_s
    st = []
    while st is not None:
        st = re.search('([0-9]+[.]{0,1}[0-9]*)\/([0-9]+[.]{0,1}[0-9]*)', p)
        p = re.sub('([0-9]+[.]{0,1}[0-9]*)\/([0-9]+[.]{0,1}[0-9]+)', cal_div, p, count=1)
    st = []
    while st is not None:
        st = re.search('([0-9]+[.]{0,1}[0-9]*)\*([0-9]+[.]{0,1}[0-9]*)', p)
        p = re.sub('([0-9]+[.]{0,1}[0-9]*)\*([0-9]+[.]{0,1}[0-9]*)', cal_mul, p, count=1)
    ## 先算负的，再算正的，防止开头是负号的情况
    st = []
    while st is not None:
        st = re.search('([0-9]*[.]{0,1}[0-9]*)\-([0-9]+[.]{0,1}[0-9]*)', p)
        p = re.sub('([0-9]*[.]{0,1}[0-9]*)\-([0-9]+[.]{0,1}[0-9]*)', cal_sub, p, count=1)
    st = []
    while st is not None:
        st = re.search('([0-9]+[.]{0,1}[0-9]*)\+([0-9]+[.]{0,1}[0-9]*)', p)
        p = re.sub('([0-9]+[.]{0,1}[0-9]*)\+([0-9]+[.]{0,1}[0-9]*)', cal_add, p, count=1)
    a = float(p)
    if len(p) > 1 and p[0] == '0' and p[1] == '0':
        a = -a
    return a
print(cal_final(p))
print(eval(s))