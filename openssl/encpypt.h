#ifndef ENCPYPT_H
#define ENCPYPT_H
#include"source.h"

class Encpypt {
public:
	Encpypt(unsigned char* datas, int len);
	//对称加密

	// RC4
	void RC4_Test();

	// DES
	void DES_Test();

	// DES3
	void DES3_Test();

	// AES
	void AES_Test();

	//非对称加密
	
	// RSA
	
	/* 公钥加密 */
	int public_key_encrypt(unsigned char* data, int len, unsigned char* en_data);

	/* 私钥解密 */
	int private_key_decrypt(unsigned char* en_data, int len, unsigned char* de_data);
private:

	unsigned char* keyflow = (unsigned char*)"This is key flow";
	unsigned char* datas;

	int len = 0;
	const int PADDING = RSA_PKCS1_PADDING;
	unsigned char* publicKey = (unsigned char*)"-----BEGIN PUBLIC KEY-----\n"
		"MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCrPgCMJW17JN2DW7tZFk/FB6pU\n"
		"pLvLOo6G/EuND8XZptffXbyiY2VscMRhP+kKVeaLO9HuEYR3Zl78x8oR6prytstc\n"
		"/MueersWDxh4iGSHsZXGxA41hXrXLRElrSTRc43ea18o0zMxZoVZiR2JFt7QcgM+\n"
		"T6eOrvj59MhXv9O46QIDAQAB\n"
		"-----END PUBLIC KEY-----\n";

	unsigned char* privateKey =(unsigned char*) "-----BEGIN RSA PRIVATE KEY-----\n"
		"MIICdgIBADANBgkqhkiG9w0BAQEFAASCAmAwggJcAgEAAoGBAKs+AIwlbXsk3YNb\n"
		"u1kWT8UHqlSku8s6job8S40Pxdmm199dvKJjZWxwxGE/6QpV5os70e4RhHdmXvzH\n"
		"yhHqmvK2y1z8y556uxYPGHiIZIexlcbEDjWFetctESWtJNFzjd5rXyjTMzFmhVmJ\n"
		"HYkW3tByAz5Pp46u+Pn0yFe/07jpAgMBAAECgYBj1YH8MtXhNVzveEuBZMCc3hsv\n"
		"vdq+YSU3DV/+nXN7sQmp77xJ8CjxT80t5VS38dy2z+lUImJYOhamyNPGHkC2y84V\n"
		"7i5+e6ScQve1gnwHqRKGBjtSCaYOqm9rTDECCTT1oMU26sfYznWlJqMrkJp1jWn7\n"
		"aAwr+3FcX2XhD74ZAQJBAN34Y6fmHLRPv21MsdgGqUjKgyFvJfLUmtFFgb6sLEWc\n"
		"k22J3BAFAcNCTLYHFZwMhL/nwaw9/7rIUJD+lcl6n3cCQQDFfrN14qKC3GJfoBZ8\n"
		"k9S6F7Ss514DDPzIuenbafhoUjZDVcjLw9EmYZQjpfsQ3WdNICUKRrDHZay1Pz+s\n"
		"YkKfAkB+OKfaquS5t/t/2LPsxuTuipIEqiKnMjSTOfYsidVnBEFlcZZc2awF76aV\n"
		"f/PO1+OJCO2910ebXBtMSCi++GbDAkEAmc7zNPwsVH4OnyquWJdJNSUBMSd/sCCN\n"
		"PkaMOrVtINHmMMq+dvMqEBoupRS/U4Ma0JYYQsiLJL+qof2AOWDNQQJAcquLGHLT\n"
		"eGDDLluHo+kkIGwZi4aK/fDoylZ0NCEtYyMtShQ3JmllST9kmb9NJX2gMsejsirc\n"
		"H6ObxqZPbka6UA==\n"
		"-----END RSA PRIVATE KEY-----\n";
};
#endif // !ENCPYPT_H
