
#ifndef _FONTS_MANAGER_H
#define _FONTS_MANAGER_H

typedef struct FontBitMap {
	int iXLeft;  /* λͼ���Ͻ�X���� */
	int iYTop;   /* λͼ���Ͻ�Y���� */
	int iXMax;   /* λͼ�����X����ֵ */
	int iYMax;   /* λͼ�����Y����ֵ */
	int iBpp;    /* λͼ��һ�������ö���λ����ʾ */
	int iPitch;  /* ���ڵ�ɫλͼ, ��������֮��Ŀ��, ����N�С���N+1����������֮���ƫ��ֵ */
	int iCurOriginX;  /* λͼ��ԭ��X����(һ�������½�), ʹ��ԭ����ȷ�������ַ���λ�� */
	int iCurOriginY;  /* λͼ��ԭ��Y���� */
	int iNextOriginX; /* ��һ���ַ����ұ��ַ���ԭ��X���� */
	int iNextOriginY; /* ��һ���ַ����ұ��ַ���ԭ��Y���� */
	unsigned char *pucBuffer;  /* �����ַ���λͼ���� */
}T_FontBitMap, *PT_FontBitMap;

typedef struct FontOpr {
	char *name;             /* ����ģ������� */
	int (*FontInit)(char *pcFontFile, unsigned int dwFontSize);  /* ����ģ��ĳ�ʼ������ */
	int (*GetFontBitmap)(unsigned int dwCode, PT_FontBitMap ptFontBitMap);  /* ���ݱ���ֵ����ַ���λͼ */
	void (*SetFontSize)(unsigned int dwFontSize);   /* ��������ߴ�(��λ:����) */
	struct FontOpr *ptNext;  /* ���� */
}T_FontOpr, *PT_FontOpr;


/**********************************************************************
 * �������ƣ� RegisterFontOpr
 * ���������� ע��"����ģ��", ��ν����ģ�����ȡ���ַ�λͼ�ķ���
 * ��������� ptFontOpr - һ���ṹ��,�ں�"ȡ���ַ�λͼ"�Ĳ�������
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
int RegisterFontOpr(PT_FontOpr ptFontOpr);

/**********************************************************************
 * �������ƣ� ShowFontOpr
 * ���������� ��ʾ��������֧�ֵ�"����ģ��"
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
void ShowFontOpr(void);

/**********************************************************************
 * �������ƣ� FontsInit
 * ���������� ���ø�������ģ��ĳ�ʼ������
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
int FontsInit(void);

/**********************************************************************
 * �������ƣ� ASCIIInit
 * ���������� ע��"ASCII����ģ��"
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
int ASCIIInit(void);

/**********************************************************************
 * �������ƣ� GBKInit
 * ���������� ע��"GBK����ģ��"
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
int GBKInit(void);

/**********************************************************************
 * �������ƣ� FreeTypeInit
 * ���������� ע��"FreeType����ģ��"
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� 0 - �ɹ�, ����ֵ - ʧ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
int FreeTypeInit(void);

/**********************************************************************
 * �������ƣ� GetFontOpr
 * ���������� ��������ȡ��ָ����"����ģ��"
 * ��������� pcName - ����
 * ��������� ��
 * �� �� ֵ�� NULL   - ʧ��,û��ָ����ģ��, 
 *            ��NULL - ����ģ���PT_FontOpr�ṹ��ָ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
PT_FontOpr GetFontOpr(char *pcName);

/**********************************************************************
 * �������ƣ� SetFontSize
 * ���������� �����ַ��ĳߴ�(��λ:ɫ��)
 * ��������� dwFontSize - �ַ��ĳߴ�(��λ:ɫ��)
 * ��������� ��
 * �� �� ֵ�� ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
void SetFontSize(unsigned int dwFontSize);

/**********************************************************************
 * �������ƣ� GetFontSize
 * ���������� ����ַ��ĳߴ�(��λ:ɫ��)
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� �ַ��ĳߴ�(��λ:ɫ��)
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
unsigned int GetFontSize(void);

/**********************************************************************
 * �������ƣ� GetFontBitmap
 * ���������� ����ַ���λͼ
 * ��������� dwCode       - �ַ��ı���ֵ(������ASCII/GBK/UNICODE)
 * ��������� ptFontBitMap - �ں�λͼ��Ϣ
 * �� �� ֵ�� 0  - �ɹ�
 *            -1 - ʧ�� 
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
int GetFontBitmap(unsigned int dwCode, PT_FontBitMap ptFontBitMap);

/**********************************************************************
 * �������ƣ� SetFontsDetail
 * ���������� ��������ģ�����Ϣ,����ָ���ֿ��ļ�,ָ���ַ��ߴ�
 * ��������� pcFontsName - Ҫ���õ�����ģ�������
 *            pcFontsFile - �ֿ��ļ�
 *            dwFontSize  - �ַ��ĳߴ�(��λ:ɫ��), ��������ʱ����SetFontSize�޸�
 * ��������� ��
 * �� �� ֵ�� 0      - �ɹ�
 *            ����ֵ - ʧ�� 
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2013/02/08	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
int SetFontsDetail(char *pcFontsName, char *pcFontsFile, unsigned int dwFontSize);

#endif /* _FONTS_MANAGER_H */
