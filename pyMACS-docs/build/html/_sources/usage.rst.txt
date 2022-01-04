Usage
=====

Installation
------------

To use pyMACS, download the source files on Github. Move them to a directory of your choice, in this 
example we will make a new directory. For example,

.. code-block:: console

	(myenv) $ cd ~/Documents
	(myenv) $ git clone htpps://github.com/thallor1/pyMACS

Now, to use pyMACS in a python script we would first have to add the base directory to our path in the following way:

.. code-block:: python

	import sys
	import os
	pyMACS_path = /Documents/pyMACS/pyMACS
	sys.path.append(0,pyMACS_path)
	from virtualMACS imoport virtualMACS

	