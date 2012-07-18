from distutils.core import setup

with open("README.rst") as fh:
    long_description = fh.read()

setup(name = 'foobar2',         
      version = '0.1',              
      description = 'A hello-world of distutils',
      author = 'ksl',
      author_email = 'kevinslin8@gmail.com',
      url = 'kevinslin.com',
      long_description = long_description,
      py_modules = ['foo'],      
      package_dir = {" ":"src"},
      packages = [''],      
      requires = ['Django (>1.4)'],
      )    
      
