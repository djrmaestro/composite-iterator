Questions
---------

In Composite Design Pattern, does 'adopt()' mean 'take ownership of'--not sure?

How do you used shared_ptr correctly in function calls?

Resources
---------

shared_ptr articles:
++++++++++++++++++++

`Smart Pointer Parameters <https://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters>`_

Guideline: Only pass reference counted pointers when you want to particiapte in managing the pointer. Use a 'shared_ptr&' parameter only to modify the shared_ptr. Use a 'const shared_ptr&' as a parameter only if you’re not sure whether
or not you’ll take a copy and share ownership; otherwise, use widget* instead (or if not nullable, a widget&).


Pattern Hatching Slides
+++++++++++++++++++++++

`Pattern Hatching slides <http://www.cs.olemiss.edu/~hcc/softwareDesign/notes/Designing_with_patterns.ppt>`_
