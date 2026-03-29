# варіянт 14
import math
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return '(' + str(self.x) + "," + str(self.y) + ")"

class Triangle:
    def __init__(self, point1, point2, point3):
        self.point1 = point1
        self.point2 = point2
        self.point3 = point3

    def __str__(self):
        return "Трикутник із вершинами:" + str(self.point1) + ", " + str(self.point2) + ", " + str(self.point3)

    def side_lengths(self):
        a = math.sqrt((self.point2.x - self.point1.x)**2 + (self.point2.y - self.point1.y)**2)
        b = math.sqrt((self.point3.x - self.point2.x)**2 + (self.point3.y - self.point2.y)**2)
        c = math.sqrt((self.point1.x - self.point3.x)**2 + (self.point1.y - self.point3.y)**2)
        return (a, b, c)

    def area(self):
        a, b, c = self.side_lengths()
        p = (a + b + c) / 2
        s = math.sqrt(p*(p - a)*(p - b)*(p - c))
        return s

point1 = Point(0, 0)
point2 = Point(0, 1)
point3 = Point(1, 0)

triangle = Triangle(point1, point2, point3)
print(triangle)
print("Довжини сторін:", triangle.side_lengths())
print("Площа трикутника:", triangle.area())


