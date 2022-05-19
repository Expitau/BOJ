debug = False
p = False

MAX_LOG = 31

def gen_set01(i, j):
	if(debug): 
		return f"T = abs({i}) // 2 \nT = T + 1 \n{j} = abs({i}) // T\n"
	else:
		return f"T = {i} / 2 \nT = T + 1 \n{j} = {i} / T\n"

def gen_set_number1N(d, n, flag):
	res = 	f"T = {n} - 1\n"
	res +=	f"T = T * {flag}\n"
	res += 	f"{d} = T + 1\n"
	return res

def gen_pow(a, d):
	pow_step = ""
	pow_step += "F = D % 2\n"
	pow_step += gen_set_number1N("T", "A", "F")
	pow_step += "C = C * T\n"
	pow_step += "C = C % N\n"
	pow_step += "A = A * A\n"
	pow_step += "A = A % N\n"
	if(debug):
		pow_step += "D = D // 2\n"
	else:
		pow_step += "D = D / 2\n"
	if(debug and p): pow_step += "print(C, A, D, T)\n"

	return f"A = {a}\nD = {d}\nC = 1\n" + pow_step*MAX_LOG

def gen_update(my_ans, ans, dist):
	ret  = f"F = {my_ans} - {ans}\n"
	ret += gen_set01("F", "F")
	ret += f"{dist} = {dist} * F\n"
	return ret


def gen_init():
	ret  = ""
	ret += gen_set01("X", "T")
	ret += "T = 1 - T\n"
	ret += "X = X + T\n"

	ret += f"N = X\nM = N - 1\nX = X - 1\nS = {MAX_LOG}\n"
	ret += "Y = 1\nZ = 1\nL = 1\nH = 1\n"
	if(debug):
		ret += "T = X % 2 \nS = S - T \nT = 2 - T \nX = X // T\n"*MAX_LOG
	else: 
		ret += "T = X % 2 \nS = S - T \nT = 2 - T \nX = X / T\n"*MAX_LOG
	
	ret += gen_pow(2, "X")
	ret += "P = C\n"
	ret += gen_update("P", 1, "Y")
	ret += gen_update("P", "M",  "Y")

	ret += gen_pow(7, "X")
	ret += "Q = C\n"
	ret += gen_update("Q", 1, "Z")
	ret += gen_update("Q", "M", "Z")

	ret += gen_pow(61, "X")
	ret += "R = C\n"
	ret += gen_update("R", 1, "L")
	ret += gen_update("R", "M", "L")

	if(debug and p): ret += """print("A, N, M : ", X, N, M)\n"""
	if(debug and p): ret += """print("========")\n"""


	return ret


def gen_step():
	ret = ""
	if(debug and p): ret += """print("P, Q, R, S : ", P, Q, R, S)\n"""
	if(debug and p): ret += """print("Y, Z, L : " , Y, Z, L)\n"""
	if(debug and p): ret += """print("----")\n"""

	ret += gen_set01("S", "T")
	ret += "S = S - T\n"
	ret += gen_set01("S", "F")



	ret += gen_set_number1N("U", "P", "F")
	ret += gen_set_number1N("V", "Q", "F")
	ret += gen_set_number1N("W", "R", "F")

	if(debug and p): ret += """print("U, V, W, f : ", U, V, W, F)\n"""
	if(debug and p): ret += """print("=====")\n"""

	ret += "P = P * U\n"
	ret += "P = P % N\n"
	ret += gen_update("P", "M", "Y")

	ret += "Q = Q * V\n"
	ret += "Q = Q % N\n"
	ret += gen_update("Q", "M", "Z")

	ret += "R = R * W\n"
	ret += "R = R % N\n"
	ret += gen_update("R", "M", "L")

	return ret

def gen_program():
	ret  = gen_init()
	ret += gen_step()*MAX_LOG
	
	ret += "Y = 1 - Y\nZ = 1 - Z\nL = 1 - L\n"
	ret += "Y = Y * Z\nY = Y * L\n"
	ret += "Y = 1 - Y\n"
	ret += gen_update("N", 2, "Y")
	ret += gen_update("N", 7, "Y")
	ret += gen_update("N", 61, "Y")
	ret += "Y = 1 - Y\n"

	ret += gen_update("N", 1, "H") #만약 1이라면 0으로 바꾼다 아니면 1
	ret += "Y = Y * H\n"

	return ret


f = open("program.txt", 'w')
if(debug): 
	f.write("X = int(input())\n")
f.write(gen_program())
if(debug): f.write("print(Y)")
f.close()
