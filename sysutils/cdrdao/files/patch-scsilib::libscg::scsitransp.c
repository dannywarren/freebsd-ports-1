--- scsilib/libscg/scsitransp.c.orig	Sun Sep 15 17:02:18 2002
+++ scsilib/libscg/scsitransp.c	Wed May 28 19:29:54 2003
@@ -1016,7 +1016,7 @@
 	register Uchar	*cp;
 	register int	n;
 {
-	js_fprintf(f, s);
+	js_fprintf(f, "%s", s);
 	while (--n >= 0)
 		js_fprintf(f, " %02X", *cp++);
 	js_fprintf(f, "\n");
