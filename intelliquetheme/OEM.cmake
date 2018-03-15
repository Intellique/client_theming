set( APPLICATION_NAME       "Intellique" )
set( APPLICATION_SHORTNAME  "Intellique" )
set( APPLICATION_EXECUTABLE "intellique" )
set( APPLICATION_DOMAIN     "www.intellique.com" )
set( APPLICATION_VENDOR     "Intellique" )
# set( APPLICATION_UPDATE_URL "https://updates.nextcloud.org/client/" CACHE string "URL for updater" )
set( APPLICATION_ICON_NAME  "Intellique" )

set( THEME_CLASS            "IntelliqueTheme" )
set( APPLICATION_REV_DOMAIN "com.intellique.desktopclient" )
set( WIN_SETUP_BITMAP_PATH  "${OEM_THEME_DIR}/win" )

set( MAC_INSTALLER_BACKGROUND_FILE "${OEM_THEME_DIR}/osx/installer-background.png" CACHE STRING "The MacOSX installer background image")

set( THEME_INCLUDE          "${OEM_THEME_DIR}/intelliquetheme.hpp" )
# set( APPLICATION_LICENSE    "${OEM_THEME_DIR}/license.txt )

option( WITH_CRASHREPORTER "Build crashreporter" OFF )
set( CRASHREPORTER_SUBMIT_URL "https://crash-reports.owncloud.com/submit" CACHE string "URL for crash reporter" )
set( CRASHREPORTER_ICON ":/owncloud-icon.png" )

if(CPACK_GENERATOR MATCHES "NSIS")
    SET( CPACK_PACKAGE_ICON  "{OEM_THEME_DIR}/win/installer.ico" ) # Set installer icon
endif(CPACK_GENERATOR MATCHES "NSIS")
