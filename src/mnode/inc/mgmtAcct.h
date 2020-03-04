/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TDENGINE_MGMT_ACCT_H
#define TDENGINE_MGMT_ACCT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mnode.h"

int32_t mgmtInitAccts();
void mgmtCleanUpAccts();
SAcctObj *mgmtGetAcct(char *acctName);

int32_t mgmtCheckUserLimit(SAcctObj *pAcct);
int32_t mgmtCheckDbLimit(SAcctObj *pAcct);
int32_t mgmtCheckTableLimit(SAcctObj *pAcct, int32_t numOfTimeSeries);
int32_t mgmtGetAcctMeta(STableMeta *pMeta, SShowObj *pShow, void *pConn);
int32_t mgmtRetrieveAccts(SShowObj *pShow, char *data, int32_t rows, void *pConn);

int32_t mgmtAddDbIntoAcct(SAcctObj *pAcct, SDbObj *pDb);
int32_t mgmtRemoveDbFromAcct(SAcctObj *pAcct, SDbObj *pDb);
int32_t mgmtAddUserIntoAcct(SAcctObj *pAcct, SUserObj *pUser);
int32_t mgmtRemoveUserFromAcct(SAcctObj *pAcct, SUserObj *pUser);

extern int32_t (*mgmtCreateAcctFp)(char *name, char *pass, SAcctCfg *pCfg);
extern int32_t (*mgmtDropAcctFp)(char *name);
extern int32_t (*mgmtAlterAcctFp)(char *name, char *pass, SAcctCfg *pCfg);

#ifdef __cplusplus
}
#endif

#endif
