--- lib/setup.py.orig	Mon Jul 23 20:38:19 2001
+++ lib/setup.py	Sat Mar 23 09:14:04 2002
@@ -7,7 +7,7 @@
 	import os, sys
 	from distutils.core import setup, Extension
 
-	if sys.platform in ['win32', 'sunos5', 'freebsd4', 'aix4', 'mac']:
+	if sys.platform in ['win32', 'sunos5', 'freebsd4', 'freebsd5', 'aix4', 'mac']:
 		LIBS=[]
 	else:
 		raise ValueError, "Don't know about platform:"+sys.platform
@@ -18,23 +18,27 @@
 			author = "Robin Becker",
 			author_email = "robin@reportlab.com",
 			url = "http://www.reportlab.com",
-			packages = [],
-			ext_modules =	[Extension(	'_rl_accel',
-										['_rl_accel.c'],
+			packages = ['reportlab',
+				'reportlab.lib', 'reportlab.extensions', 'reportlab.graphics',
+				'reportlab.pdfbase', 'reportlab.pdfgen', 'reportlab.platypus',
+				'reportlab.tools', 'reportlab.tools.docco',
+				'reportlab.tools.py2pdf', 'reportlab.tools.pythonpoint'],
+			ext_modules =	[Extension(	'reportlab.lib._rl_accel',
+										['reportlab/lib/_rl_accel.c'],
 										include_dirs=[],
 										define_macros=[],
 										library_dirs=[],
 										libraries=LIBS,	# libraries to link against
 										),
-							Extension(	'sgmlop',
-										['sgmlop.c'],
+							Extension(	'reportlab.lib.sgmlop',
+										['reportlab/lib/sgmlop.c'],
 										include_dirs=[],
 										define_macros=[],
 										library_dirs=[],
 										libraries=LIBS,	# libraries to link against
 										),
-							Extension(	'pyHnj',
-										['pyHnjmodule.c','hyphen.c', 'hnjalloc.c'],
+							Extension(	'reportlab.lib.pyHnj',
+										['reportlab/lib/pyHnjmodule.c','reportlab/lib/hyphen.c', 'reportlab/lib/hnjalloc.c'],
 										include_dirs=[],
 										define_macros=[],
 										library_dirs=[],
