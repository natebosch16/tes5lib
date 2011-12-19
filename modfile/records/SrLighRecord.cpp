/*===========================================================================
 *
 * File:		SrLighRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srLighrecord.h"


srlighdata_t CSrLighRecord::s_NullLightData;


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrLighRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODL, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FNAM, CSrFloatSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrLighDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrLStringSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLighRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrLighRecord, CSrIdRecord)
	ADD_SRFIELDALL("HoldSound",		SR_FIELD_HOLDSOUND,			0, CSrLighRecord, FieldHoldSound)
	ADD_SRFIELDALL("FName",			SR_FIELD_UNKNOWN7,				0, CSrLighRecord, FieldFNam)
	ADD_SRFIELDALL("Model",			SR_FIELD_MODEL,				0, CSrLighRecord, FieldModel)
	ADD_SRFIELDALL("ItemName",		SR_FIELD_ITEMNAME,			0, CSrLighRecord, FieldItemName)
	ADD_SRFIELDALL("Time",			SR_FIELD_TIME,				0, CSrLighRecord, FieldTime)
	ADD_SRFIELDALL("Radius",		SR_FIELD_RADIUS,			0, CSrLighRecord, FieldRadius)
	ADD_SRFIELDALL("Color",			SR_FIELD_COLOR,				0, CSrLighRecord, FieldColor)
	ADD_SRFIELDALL("Falloff",		SR_FIELD_FALLOFF,			0, CSrLighRecord, FieldFallOff)
	ADD_SRFIELDALL("FOV",			SR_FIELD_FOV,				0, CSrLighRecord, FieldFOV)
	ADD_SRFIELDALL("Value",			SR_FIELD_VALUE,				0, CSrLighRecord, FieldValue)
	ADD_SRFIELDALL("Unknown1",		SR_FIELD_UNKNOWN1,			0, CSrLighRecord, FieldUnknown1)
	ADD_SRFIELDALL("Unknown2",		SR_FIELD_UNKNOWN2,			0, CSrLighRecord, FieldUnknown2)
	ADD_SRFIELDALL("Unknown3",		SR_FIELD_UNKNOWN3,			0, CSrLighRecord, FieldUnknown3)
	ADD_SRFIELDALL("Unknown4",		SR_FIELD_UNKNOWN4,			0, CSrLighRecord, FieldUnknown4)
	ADD_SRFIELDALL("Unknown5",		SR_FIELD_UNKNOWN5,			0, CSrLighRecord, FieldUnknown5)
	ADD_SRFIELDALL("Weight",		SR_FIELD_WEIGHT,			0, CSrLighRecord, FieldWeight)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CSrLighRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLighRecord Constructor
 *
 *=========================================================================*/
CSrLighRecord::CSrLighRecord () 
{
	m_pModel = NULL;
	m_pFnamData = NULL;
	m_pObndData = NULL;
	m_pLightData = NULL;
	m_pModtData = NULL;
	m_pSnamData = NULL;
	m_pItemName = NULL;
}
/*===========================================================================
 *		End of Class CSrLighRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLighRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrLighRecord::Destroy (void) 
{
	m_pModel = NULL;
	m_pFnamData = NULL;
	m_pObndData = NULL;
	m_pLightData = NULL;
	m_pModtData = NULL;
	m_pSnamData = NULL;
	m_pItemName = NULL;

	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrLighRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLighRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrLighRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrLighRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLighRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLighRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_MODL)
	{
		m_pModel = SrCastClass(CSrStringSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FNAM)
	{
		m_pFnamData = SrCastClass(CSrFloatSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pLightData = SrCastClass(CSrLighDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_MODT)
	{
		m_pModtData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SNAM)
	{
		m_pSnamData = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pItemName = SrCastClass(CSrLStringSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrLighRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLighRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLighRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pModel == pSubrecord)
		m_pModel = NULL;
	else if (m_pFnamData == pSubrecord)
		m_pFnamData = NULL;
	else if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pLightData == pSubrecord)
		m_pLightData = NULL;
	else if (m_pModtData == pSubrecord)
		m_pModtData = NULL;
	else if (m_pSnamData == pSubrecord)
		m_pSnamData = NULL;
	else if (m_pItemName == pSubrecord)
		m_pItemName = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrLighRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLighRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLighRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLighRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLighRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLighRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLighRecord Set Field Methods
 *=========================================================================*/
