from distutils.core import setup
setup(name='entanglementspendfrom',
      version='1.0',
      description='Command-line utility for entanglement "coin control"',
      author='Gavin Andresen',
      author_email='contact@entanglement.io',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
