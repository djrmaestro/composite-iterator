Questions
---------

1. n Composite Design Pattern, does 'adopt()' mean 'take ownership of'? Does the composite in the Compoiste Pattern own the objects it composes?

2. How do you used shared_ptr correctly in function calls?

Resources
---------

shared_ptr articles:
++++++++++++++++++++

`Smart Pointer Parameters <https://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters>`_

    Guideline: Don’t pass a smart pointer as a function parameter unless you want to use or manipulate the smart pointer itself, such as to share or transfer ownership.

    Guideline: Prefer passing objects by value, *, or &, not by smart pointer.

Pattern Hatching Slides
+++++++++++++++++++++++

`Pattern Hatching slides <http://www.cs.olemiss.edu/~hcc/softwareDesign/notes/Designing_with_patterns.ppt>`_
