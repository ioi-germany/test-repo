title("Sum")
tokens(2,2,timedelta(minutes=30))
submission_limits(50,None)
user_test_limits(50,timedelta(minutes=1))
batch(comparator=compile("comparator.cpp", use_lib=True))
timelimit(1)
memorylimit(256)

auto_feedback_groups()

output_generator(compile("solution.cpp"))
test_submission("solution.cpp")
test_submission("solution-int.cpp", wrong_output = [3])
test_submission("off-by-1.cpp")
test_submission("counter.cpp", timeout = [3], out_of_memory = [3])
test_submission("solution.pas")
test_submission("compilefail.cpp")
test_submission("zerofail.cpp", out_of_memory = [1.1] )
test_submission("garbage.cpp", wrong_output = [0, 1.1, 2, 3], dont_care = [1.2])
test_submission("trailingspace.cpp")

gen = compile("gen")

# Public
with subtask("Public", public=True) as s:
    with group(100):
        testcase(explicit, "1.in", save=True)

# Subtask 1
with subtask("Subtask 1") as s:
    with group(10):
        testcase(gen, 1, 0, detailed = True)
    with group(40):
        testcase(gen, 341, 2000, detailed = True)
        testcase(gen, 42, 12)

# detailed feedback subtask will be inserted here automatically

# Subtask 2
with subtask("Subtask 2") as s:
    with group(50):
        testcase(gen, 43, 324232, detailed = True)
        testcase(gen, 43, 1000000000000000000)

# detailed feedback subtask will be inserted here automatically

statement(compile("statement"))
