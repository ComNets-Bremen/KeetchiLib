/******************************************************************************
 * Keetchi - A library for opportunistic communications.
 *
 * Copyright (C) 2016, Communication Networks, University of Bremen, Germany
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 * This file is part of the Keetchi library
 *
 ******************************************************************************/

/**
*
* @author : Asanga Udugama (adu@comnets.uni-bremen.de)
* @date   : 22-Sept-2015
*
*/
#include "KLResourceMgr.h"

KLResourceMgr::KLResourceMgr(string ownAddr, string ownNme)
{
    ownAddress = ownAddr;
    ownName = ownNme;
}

KLResourceMgr::~KLResourceMgr(void)
{
	
}

int KLResourceMgr::determineResourceLimitationStatus(double cTime)
{
	return KLKEETCHI_RESOURCE_CAPACITY_LEVEL_99;
}
