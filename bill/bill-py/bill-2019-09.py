# -*- coding:utf8 -*-
# 绘制2019年9月消费 条形图（横着的）
from matplotlib import pyplot as plt
import matplotlib
# 设置中文编码
matplotlib.rc("font", family="SimHei", weight='bold')
# a表示日期，
# b表示对应的日消费（单位为元）
a = ["1日", "2日", "3日", "4日", "5日", "6日", "7日", "8日", "9日", "10日",
     "11日", "12日", "13日", "14日", "15日", "16日", "17日", "18日", "19日", "20日",
     "21日", "22日", "23日", "24日", "25日", "26日", "27日", "28日", "29日", "30日"]
b = [36.39, 14, 21, 18, 13, 12, 14.6, 12, 13, 16.5,
     23.5, 24, 94.6, 19.09, 55, 28, 16.2, 9, 0, 13.79,
     19.2, 0, 71, 17, 31.6, 19, 32.9, 20, 15, 50.57]

# 计算月消费总额
num = 0
for i in b:
    num += i
num_str = str(num)
print(num_str)

# 设置图形大小
# 设置大小应该在绘制图形前面
plt.figure(figsize=(15, 8), dpi=80)


plt.xlabel('横轴：日期', fontsize=15, color="r")
plt.ylabel('纵轴：金额\n 单位：元', fontsize=15, color="r")

# 绘制条形图（横着的）
# 前面两个分别是y轴和x轴的刻度，都是数字数组
# height调整条形图的宽度
# color调整条形图的颜色
plt.bar(range(len(a)), b, width=0.8, color="orange", label="2019年9月账单:总计"+num_str)

# 添加图例
#     设置完label之后，还要legend()才显示
plt.legend()

plt.title("2019年9月账单", fontsize=18)
# print(type(int(b[0])))
for i in a:
    myi = int(i.split("日")[0])
    plt.text(myi-1.3, int(b[myi-1])+0.8, str(b[myi-1]), fontsize=13)

# 设置x轴的刻度
#     第一个表示刻度值,
#     第二个表示刻度值对应的备注
plt.xticks(range(len(a)), a)

plt.grid(axis="y", linestyle=":", color="g")

# 显示绘制图形
plt.show()

