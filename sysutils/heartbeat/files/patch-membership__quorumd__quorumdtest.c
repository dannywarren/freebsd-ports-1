--- membership/quorumd/quorumdtest.c.orig	2008-08-18 12:32:19 UTC
+++ membership/quorumd/quorumdtest.c
@@ -136,11 +136,9 @@ initialize_tls_session (int sd)
 {
 	int ret;
 	gnutls_session session;
-	const int cert_type_priority[2] = { GNUTLS_CRT_X509,0};
 	
 	gnutls_init (&session, GNUTLS_CLIENT);
 	gnutls_set_default_priority (session);
-	gnutls_certificate_type_set_priority (session, cert_type_priority);
 	gnutls_credentials_set (session, GNUTLS_CRD_CERTIFICATE, xcred);
 	gnutls_transport_set_ptr (session, (gnutls_transport_ptr) GINT_TO_POINTER(sd));
 	ret = gnutls_handshake (session);
@@ -162,16 +160,16 @@ verify_certificate (gnutls_session sessi
 	unsigned int cert_list_size;
 	const gnutls_datum *cert_list;
 	int ret;
+	int status;
 	gnutls_x509_crt cert;
 
-	ret = gnutls_certificate_verify_peers (session);
+	ret = gnutls_certificate_verify_peers2 (session, &status);
 
 	if (ret < 0)
 	{
 		printf("gnutls_certificate_verify_peers2 returns error.\n");
 		return -1;
 	}
-/*	
 	if (status & GNUTLS_CERT_INVALID) {
 		printf("The certificate is not trusted.\n");
 		return -1;
@@ -184,7 +182,6 @@ verify_certificate (gnutls_session sessi
 		printf("The certificate has been revoked.\n");
 		return -1;
 	}
-*/	
 	if (gnutls_certificate_type_get (session) != GNUTLS_CRT_X509) {
 		printf("The certificate is not a x.509 cert\n");
     		return -1;
