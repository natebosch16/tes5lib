/*===========================================================================
 *
 * File:		Srmgefdatasubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	1 December 2011
 *
 * Description
 *
 *=========================================================================*/
#ifndef __SRMGEFDATASUBRECORD_H
#define __SRMGEFDATASUBRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "srsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/

	#define SR_MGEFDATA_SUBRECORD_SIZE	152

		/* All flags not yet confirmed (some taken from Oblivion) */
	#define SR_MGEFFLAG_HOSTILE			0x00000001
    #define SR_MGEFFLAG_RECOVER			0x00000002
    #define SR_MGEFFLAG_DETRIMENTAL		0x00000004
    #define SR_MGEFFLAG_PERCENTMAG		0x00000008
    #define SR_MGEFFLAG_SELF			0x00000010
    #define SR_MGEFFLAG_00000100		0x00000100
    #define SR_MGEFFLAG_NOAREA			0x00000200
    #define SR_MGEFFLAG_FXPERSIST		0x00000400
    #define SR_MGEFFLAG_00000800		0x00000800
    #define SR_MGEFFLAG_00001000		0x00001000
	#define SR_MGEFFLAG_00004000		0x00004000
	#define SR_MGEFFLAG_00008000		0x00008000
    #define SR_MGEFFLAG_00020000		0x00020000
	#define SR_MGEFFLAG_BOUND			0x00040000
    #define SR_MGEFFLAG_04000000		0x04000000
    #define SR_MGEFFLAG_08000000		0x08000000
	#define SR_MGEFFLAG_10000000		0x10000000
	#define SR_MGEFFLAG_40000000		0x40000000

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 * 
 *=========================================================================*/
#pragma pack(push, 1)

  struct srmgefdata_t 
  {
	  dword			Flags;
	  float			BaseCost;
	  srformid_t	SecondSpellID;
	  dword			School;
	  dword			EffectType;
	  dword			Unknown3;
	  srformid_t	LightID;
	  dword			Unknown4;
	  srformid_t	ShaderID1;
	  srformid_t	ShaderID2;
	  dword			SkillLevel;
	  dword			Unknown7;
	  float			CastingDelay;
	  dword			Unknown9;
	  dword			Unknown10;
	  dword			Unknown11;
	  dword			Unknown12;
	  dword			ActorValue;
	  srformid_t	ProjectileID;
	  dword			Unknown14;
	  dword			CastType;
	  dword			Unknown16;
	  dword			Unknown17;
	  srformid_t	ArtID1;
	  srformid_t	ArtID2;
	  srformid_t	ImpactSetID;
	  float			EffectPlayRate;
	  dword			Unknown18;
	  float			Unknown19;
	  dword			Unknown20;
	  dword			Unknown21;
	  dword			Unknown22;
	  float			Unknown23;
	  dword			Unknown24[5];
  };

#pragma pack(pop)
/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrMgefDataSubrecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrMgefDataSubrecord : public CSrSubrecord {
  DECLARE_SRCLASS(CSrMgefDataSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  srmgefdata_t	m_Data;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

	/* Input/output the subrecord data */
  virtual bool ReadData  (CSrFile& File) { memset(&m_Data, 0, sizeof(m_Data)); return File.Read(&m_Data,  m_RecordSize); }
  virtual bool WriteData (CSrFile& File) { return File.Write(&m_Data, m_RecordSize); }


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrMgefDataSubrecord() { }
  //virtual ~CSrMgefDataSubrecord() { Destroy(); }
  virtual void Destroy (void) { CSrSubrecord::Destroy(); }
  
  	/* Change any matching formid in the subrecord */
  virtual dword ChangeFormID (const srformid_t NewID, const srformid_t OldID) { 
       
	return (0);
  }

 	/* Copy the content from an existing subrecord */
  virtual bool Copy (CSrSubrecord* pSubrecord) {
	CSrMgefDataSubrecord* pSubrecord1 = SrCastClassNull(CSrMgefDataSubrecord, pSubrecord);
	m_RecordSize = SR_MGEFDATA_SUBRECORD_SIZE;

	if (pSubrecord1 != NULL) {
	  m_Data = pSubrecord1->GetEffectData();
	}
	else {
	  memset(&m_Data, 0, sizeof(m_Data));
	}
	return (true);
  }

  	/* Create a class instance */
  static CSrSubrecord* Create (void) { return (new CSrMgefDataSubrecord); }

  	/* Fixup the modindex of formids */
  virtual bool FixupFormID (CSrFormidFixupArray& FixupArray) {
	return true;
  }

	/* Get class members */
  srmgefdata_t& GetEffectData (void) { return (m_Data); }
  virtual byte*	GetData       (void) { return (byte *)(&m_Data); }
    
	/* Initialize a new record */
  void InitializeNew (void) { CSrSubrecord::InitializeNew(); memset(&m_Data, 0, sizeof(m_Data)); m_RecordSize = SR_MGEFDATA_SUBRECORD_SIZE; }

	/* Set class members */

};
/*===========================================================================
 *		End of Class CSrMgefDataSubrecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrMgefDatasubrecord.H
 *=========================================================================*/
