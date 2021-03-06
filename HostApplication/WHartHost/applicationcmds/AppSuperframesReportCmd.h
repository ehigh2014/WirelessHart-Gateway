/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#ifndef __APPSUPERFRAMESREPORTCMD_H_
#define __APPSUPERFRAMESREPORTCMD_H_

#include <WHartHost/applicationcmds/AbstractAppCommand.h>
#include <WHartHost/database/DevicesManager.h>


namespace hart7 {
namespace hostapp {

class IAppCommandVisitor;
class AppSuperframesReportCmd;

typedef boost::shared_ptr<AppSuperframesReportCmd> AppSuperframesReportCmdPtr;

class AppSuperframesReportCmd: public AbstractAppCommand
{

public:
	AppSuperframesReportCmd(int p_nNbOfNeededReports);
	virtual bool Accept(IAppCommandVisitor& visitor);

protected:
	void DumpToStream(std::ostream& p_rStream) const;

public:
	void ReportReceived();
	bool ReceivedAllReports();
	SuperframesListT& GetSuperframes();

private:
	int m_nNbOfNeededReports;

private:
	bool m_nbCleaned;
	SuperframesListT m_Superframes;
};

}
}

#endif //__APPSUPERFRAMESREPORTCMD_H_

