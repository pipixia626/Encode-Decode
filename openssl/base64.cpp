#include"base64.h"
// ±àÂë: 
// @param: const char* in ÊäÈë´ı±àÂë×Ö·û´® 
// @param: int            ´ı±àÂë×Ö·û´®³¤¶È
// @ret: ·µ»Ø             ±àÂë×Ö·û´®
char* Base64::Base64Encode(const char* in, int len)
{ 
	BIO* bmem = NULL;
	BIO* b64 = NULL;
	BUF_MEM* bptr = NULL;

	b64 = BIO_new(BIO_f_base64());

	bmem = BIO_new(BIO_s_mem());
	b64 = BIO_push(b64, bmem);
	BIO_write(b64, in, len);
	BIO_flush(b64);
	BIO_get_mem_ptr(b64, &bptr);

	char* buff = (char*)malloc(bptr->length + 1);
	memcpy(buff, bptr->data, bptr->length);
	buff[bptr->length] = 0;

	BIO_free_all(b64);

	return buff;
}
// ½âÂë: 
// @param: const char* in ÊäÈë´ı½âÂë×Ö·û´® 
// @param: int            ´ı½âÂë×Ö·û´®³¤¶È
// @ret: ·µ»Ø             ½âÂë×Ö·û´®
char* Base64::Base64Decode(const char* in, int len)
{
	BIO* b64 = NULL;
	BIO* bmem = NULL;
	char* buff = (char*)malloc(len);
	memset(buff, 0, len);

	b64 = BIO_new(BIO_f_base64());

	bmem = BIO_new_mem_buf(in, len);
	bmem = BIO_push(b64, bmem);
	BIO_read(bmem, buff, len);

	BIO_free_all(bmem);

	return buff;
	
}
