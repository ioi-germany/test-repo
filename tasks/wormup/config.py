title("Wormup")
tokens(2,2,timedelta(minutes=30))
submission_limits(50,None)
user_test_limits(50,timedelta(minutes=1))
batch(comparator = token_equ)
timelimit(1)
memorylimit(128)

task.checker(compile("checker", use_lib = True))

output_generator(compile("solution1"))
gen = compile("gen")

# Make test cases before actually using them.
# This way, each test case is created only once and can be used in multiple subtasks.
tcs = [make_testcase(gen, stdin="{}.ing".format(i)) for i in range(16)]

def testcaserange(start, end):
    for i in range(start, end + 1):
        add_testcase(tcs[i])

task.constraint("M: [0,24] x,y: [1,5]")

with subtask("Public", True) as s:
    with group(1):
        add_testcase(tcs[0], save=True)

with subtask("1") as s:
    s.constraint("M: [15,]")
    with group(40):
        testcaserange(1, 5)

with subtask("2") as s:
    with group(30):
        testcaserange(6, 10)

with subtask("3") as s:
    with group(30):
        testcaserange(11, 15)

with subtask("Detailed Feedback 1", True) as s:
    s.constraint("M: [15,]")
    with group(39):
        testcaserange(1, 3)

with subtask("Detailed Feedback 2", True) as s:
    with group(60):
        testcaserange(8, 12)

statement(compile("statement"))

test_submission("solution1.cpp", wrong_output = [1])
test_submission("solution2.cpp")
test_submission("demo.cpp", strong_mem_limit = 0.000000000001)

# Create test case images
for c in task.cases:
    compile("testimg.asy", stdin=c.infile, output="testcase{}.pdf".format(c.codename))
