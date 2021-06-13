enum unicode_names {
  AGRAVE,
  ACIRC,
  AUML, 
  CCEDIL, 
  EGRAVE,
  EACUTE,
  ECIRC,
  EUML, 
  ICIRC, 
  IUML, 
  OCIRC, 
  OUML, 
  UGRAVE, 
  UCIRC,
  UUML,
  MAGRAVE,
  MACIRC,
  MAUML, 
  MCCEDIL, 
  MEGRAVE,
  MEACUTE,
  MECIRC,
  MEUML, 
  MICIRC, 
  MIUML, 
  MOCIRC, 
  MOUML, 
  MUGRAVE, 
  MUCIRC,
  MUUML
};

const uint32_t PROGMEM unicode_map[] = {
  [AGRAVE]  = 0x00e0, //à
  [ACIRC]  = 0x00e2, //â
  [AUML]  = 0x00e4, //ä
  [CCEDIL]  = 0x00e7, //ç
  [EGRAVE]  = 0x00e8, //è
  [EACUTE]  = 0x00e9, //é
  [ECIRC]  = 0x00ea, //ê
  [EUML]  = 0x00eb, //ë
  [ICIRC]  = 0x00ee, //î
  [IUML]  = 0x00ef, //ï
  [OCIRC]  = 0x00f4, //ô
  [OUML]  = 0x00f6, //ö
  [UGRAVE]  = 0x00f9, //ù
  [UCIRC]  = 0x00fb, //û
  [UUML]  = 0x00fc, //ü
  [MAGRAVE]  = 0x00C0, //à
  [MACIRC]  = 0x00C2, //â
  [MAUML]  = 0x00C4, //ä
  [MCCEDIL]  = 0x00C7, //ç
  [MEGRAVE]  = 0x00C8, //è
  [MEACUTE]  = 0x00C9, //é
  [MECIRC]  = 0x00Ca, //ê
  [MEUML]  = 0x00Cb, //ë
  [MICIRC]  = 0x00Ce, //î
  [MIUML]  = 0x00Cf, //ï
  [MOCIRC]  = 0x00D4, //ô
  [MOUML]  = 0x00D6, //ö
  [MUGRAVE]  = 0x00D9, //ù
  [MUCIRC]  = 0x00Db, //û
  [MUUML]  = 0x00Dc, //ü
};

#define U_AGRAVE XP(AGRAVE, MAGRAVE)
#define U_ACIRC  XP(ACIRC, MACIRC)
#define U_AUML   XP(AUML, MAUML)
#define U_CCEDIL XP(CCEDIL, MCCEDIL)
#define U_EGRAVE XP(EGRAVE, MEGRAVE)
#define U_EACUTE XP(EACUTE, MEACUTE)
#define U_ECIRC  XP(ECIRC, MECIRC)
#define U_EUML   XP(EUML, MEUML)
#define U_ICIRC  XP(ICIRC, MICIRC)
#define U_IUML   XP(IUML, MIUML)
#define U_OCIRC  XP(OCIRC, MOCIRC)
#define U_OUML   XP(OUML, MOUML)
#define U_UGRAVE XP(UGRAVE, MUGRAVE)
#define U_UCIRC  XP(UCIRC, MUCIRC)
#define U_UUML   XP(UUML, MUUML)

	


