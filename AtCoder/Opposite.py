import math
n=int(input())
x0,y0=map(int,input().split(' '))
xhalf,yhalf=map(int,input().split(' '))
center_x=(x0+xhalf)/2   # calculate the center of polygon
center_y=(y0+yhalf)/2
x0-=center_x    # shift the center to (0,0) so we can use rotation matrix
y0-=center_y
theta=2*math.pi/n
print(f'{x0*math.cos(theta) - y0*math.sin(theta) + center_x} {x0*math.sin(theta) + y0*math.cos(theta) + center_y}') #remember to shift back
"""
[cos -sin][x
[sin  cos] y]
"""