description("Test contest")
timezone("Europe/Berlin")

contest.lg = "1. Auswahllehrgang"

from cmscontrib.gerpythonformat.templates.lg.LgTemplate import LgTemplate
LgTemplate(contest)

# if a user group is named "main" and no default group is set yet, it is automatically used as default
# you can set the default explicitely by calling default_group(...) instead of user_group() (niy)
user_group("main")
special = user_group("special")

supplement_file("latex", "taskinfo.tex") # data specified below will be stored there, can be used as input for latex

with day():
    # no user group specified => default group assumed
    contest_wnd(start = time("2013-09-01 10:00:00"), stop = time("2015-09-10 13:00:00"))
    contest_wnd(special, start = time("2012-09-01 10:00:00"), stop = time("2015-09-01 13:00:00"))

    task("sum")
    task("wormup")

unit_test_user(user("test", "test"))
user("testcontesttestuser", "secret password") # implicitely in the main group
user("specialuser", "even more secret password", group = special)
