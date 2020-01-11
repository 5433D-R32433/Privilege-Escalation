#include <Windows.h>
#include <sddl.h>
#include <stdio.h>



BOOL SetPrivilege(HANDLE hToken, LPCTSTR lpszPrivilege, BOOL bEnablePrivilege)
{

        TOKEN_PRIVILEGES TP;
        LUID luid;


        if ( !LookupPrivilegeValue ( NULL, lpszPrivilege, &luid ) )
        {
                printf ( "Lookupprivilegevalue() Error: %u\n", GetLastError() );
                return FALSE;
        }
        else
        {
                printf("Lookupprivilegevalue() OK\n");
        }


        TP.PrivilegeCount = 1;
        TP.Privileges[0].Luid = luid;

        // Don't forget to disable privilege after you enable them

        if (bEnablePrivilege)
        {
                TP.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
                // Just a Verification Here
                printf("TP.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED\n");
        }
        else
        {
                TP.Privileges[0].Attributes = 0;
                printf("TP.Privileges[0].Attributes = 0\n");
        }


        // Enable Privileges (or Disable All Privileges)
        if ( !AdjustTokenPrivileges(hToken, FALSE, &TP, sizeof(TOKEN_PRIVILEGES), NULL, NULL) )
        {
                fprintf ( stderr, "Adjusttokenprivileges() Error: %u\n", GetLastError() );
                return FALSE;
        }
        else
        {
                printf("AdjustTokenprivileges() OK");

        }





        return TRUE;
}







int main(int argc, char **argv)
{







        return (0);
}
