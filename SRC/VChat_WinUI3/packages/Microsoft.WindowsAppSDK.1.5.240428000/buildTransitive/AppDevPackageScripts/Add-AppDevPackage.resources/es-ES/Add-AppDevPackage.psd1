# Localized	12/03/2020 06:20 PM (GMT)	303:4.80.0411 	Add-AppDevPackage.psd1
# Culture = "en-US"
ConvertFrom-StringData @'
###PSLOC
PromptYesString=&Sí
PromptNoString=&No
BundleFound=Agrupación encontrada: {0}
PackageFound=Paquete encontrado: {0}
EncryptedBundleFound=Se ha encontrado un conjunto cifrado: {0}
EncryptedPackageFound=Se ha encontrado un paquete cifrado: {0}
CertificateFound=Certificado encontrado: {0}
DependenciesFound=Paquetes de dependencia encontrados:
GettingDeveloperLicense=Adquiriendo licencia de desarrollador...
InstallingCertificate=Instalando certificado...
InstallingPackage=\nInstalando la aplicación...
AcquireLicenseSuccessful=Se ha adquirido correctamente una licencia de desarrollador.
InstallCertificateSuccessful=El certificado se ha instalado correctamente.
Success=\nCorrecto: la aplicación se instaló correctamente.
WarningInstallCert=\nEstá a punto de instalar un certificado digital en el almacén de certificados de personas de confianza de su equipo. Esta operación entraña un riesgo de seguridad importante, por lo que solo deberá realizarla si confía en el emisor de este certificado digital.\n\nCuando termine de usar la aplicación, deberá quitar manualmente el certificado digital asociado. Aquí encontrará instrucciones para realizar esta operación: http://go.microsoft.com/fwlink/?LinkId=243053\n\n¿Está seguro de que desea continuar?\n\n
ElevateActions=\nAntes de instalar esta aplicación, es necesario realizar lo siguiente:
ElevateActionDevLicense=\t- Adquiera una licencia de desarrollador
ElevateActionCertificate=\t- Instale el certificado de firma
ElevateActionsContinue=Se requieren credenciales de administrador para continuar. Acepte la solicitud de UAC e indique su contraseña de administrador si así se le solicita.
ErrorForceElevate=Debe indicar las credenciales de administrador para continuar. Ejecute este script sin el parámetro -Force o desde una ventana PowerShell elevada.
ErrorForceDeveloperLicense=La adquisición de una licencia de desarrollador requiere la interacción del usuario. Vuelva a ejecutar el script sin el parámetro -Force.
ErrorLaunchAdminFailed=Error: no se puede iniciar un nuevo proceso como administrador.
ErrorNoScriptPath=Error: debe iniciar este script desde un archivo.
ErrorNoPackageFound=Error: no se encontró ningún paquete o agrupación en el directorio del script. Asegúrese de que el paquete o agrupación que desea instalar se encuentre en el mismo directorio que este script.
ErrorManyPackagesFound=Error: se encontró más de un paquete o agrupación en el directorio del script. Asegúrese de que solo el paquete o agrupación que desea instalar se encuentre en el mismo directorio que este script.
ErrorPackageUnsigned=Error: el paquete o agrupación no tiene signatura digital o la signatura está dañada.
ErrorNoCertificateFound=Error: no se encuentran certificados en el directorio del script. Asegúrese de que el certificado usado para firmar el paquete o agrupación que está instalando se encuentre en el mismo directorio que este script.
ErrorManyCertificatesFound=Error: se encontró más de un certificado en el directorio del script. Asegúrese de que solo el certificado usado para firmar el paquete o agrupación que está instalando se encuentre en el mismo directorio que este script.
ErrorBadCertificate=Error: el archivo "{0}" no es un certificado digital válido. CertUtil devolvió el código de error {1}.
ErrorExpiredCertificate=Error: el certificado de desarrollador "{0}" ha expirado. Una causa posible es que el reloj del sistema no esté establecido en la fecha y la hora correctas. Si la configuración del sistema es correcta, póngase en contacto con el propietario de la aplicación para volver a crear un paquete o agrupación con un certificado válido.
ErrorCertificateMismatch=Error: el certificado no coincide con el que se usó para firmar el paquete o agrupación.
ErrorCertIsCA=Error: el certificado no puede ser una entidad de certificación.
ErrorBannedKeyUsage=Error: el certificado no puede tener el siguiente uso de clave: {0}. El uso de clave no debe estar especificado, o debe ser igual a "DigitalSignature".
ErrorBannedEKU=Error: el certificado no puede tener el siguiente uso mejorado de clave: {0}. Solo se permiten los EKU Firma de código y Firma de vigencia.
ErrorNoBasicConstraints=Error: no se encuentra la extensión de restricciones básicas del certificado.
ErrorNoCodeSigningEku=Error: no se encuentra el uso mejorado de clave de Firma de código.
ErrorInstallCertificateCancelled=Error: se canceló la instalación del certificado.
ErrorCertUtilInstallFailed=Error: no se puede instalar el certificado. CertUtil devolvió el código de error {0}.
ErrorGetDeveloperLicenseFailed=Error: no se puede adquirir una licencia de desarrollador. Para obtener más información, consulte http://go.microsoft.com/fwlink/?LinkID=252740.
ErrorInstallCertificateFailed=Error: no se puede instalar el certificado. Estado: {0}. Para obtener más información, consulte http://go.microsoft.com/fwlink/?LinkID=252740.
ErrorAddPackageFailed=Error: no se puede instalar la aplicación.
ErrorAddPackageFailedWithCert=Error: no se puede instalar la aplicación. para garantizar la seguridad, considere desinstalar el certificado de signatura hasta que pueda instalar la aplicación. Encontrará instrucciones al respecto aquí:\nhttp://go.microsoft.com/fwlink/?LinkId=243053
'@

# SIG # Begin signature block
# MIInvgYJKoZIhvcNAQcCoIInrzCCJ6sCAQExDzANBglghkgBZQMEAgEFADB5Bgor
# BgEEAYI3AgEEoGswaTA0BgorBgEEAYI3AgEeMCYCAwEAAAQQH8w7YFlLCE63JNLG
# KX7zUQIBAAIBAAIBAAIBAAIBADAxMA0GCWCGSAFlAwQCAQUABCDvGsxAW2FcI0uK
# XEdJ/9j86x2U/kKoLH3LFgUKKovBUKCCDXYwggX0MIID3KADAgECAhMzAAADrzBA
# DkyjTQVBAAAAAAOvMA0GCSqGSIb3DQEBCwUAMH4xCzAJBgNVBAYTAlVTMRMwEQYD
# VQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQKExVNaWNy
# b3NvZnQgQ29ycG9yYXRpb24xKDAmBgNVBAMTH01pY3Jvc29mdCBDb2RlIFNpZ25p
# bmcgUENBIDIwMTEwHhcNMjMxMTE2MTkwOTAwWhcNMjQxMTE0MTkwOTAwWjB0MQsw
# CQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9u
# ZDEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBvcmF0aW9uMR4wHAYDVQQDExVNaWNy
# b3NvZnQgQ29ycG9yYXRpb24wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIB
# AQDOS8s1ra6f0YGtg0OhEaQa/t3Q+q1MEHhWJhqQVuO5amYXQpy8MDPNoJYk+FWA
# hePP5LxwcSge5aen+f5Q6WNPd6EDxGzotvVpNi5ve0H97S3F7C/axDfKxyNh21MG
# 0W8Sb0vxi/vorcLHOL9i+t2D6yvvDzLlEefUCbQV/zGCBjXGlYJcUj6RAzXyeNAN
# xSpKXAGd7Fh+ocGHPPphcD9LQTOJgG7Y7aYztHqBLJiQQ4eAgZNU4ac6+8LnEGAL
# go1ydC5BJEuJQjYKbNTy959HrKSu7LO3Ws0w8jw6pYdC1IMpdTkk2puTgY2PDNzB
# tLM4evG7FYer3WX+8t1UMYNTAgMBAAGjggFzMIIBbzAfBgNVHSUEGDAWBgorBgEE
# AYI3TAgBBggrBgEFBQcDAzAdBgNVHQ4EFgQURxxxNPIEPGSO8kqz+bgCAQWGXsEw
# RQYDVR0RBD4wPKQ6MDgxHjAcBgNVBAsTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEW
# MBQGA1UEBRMNMjMwMDEyKzUwMTgyNjAfBgNVHSMEGDAWgBRIbmTlUAXTgqoXNzci
# tW2oynUClTBUBgNVHR8ETTBLMEmgR6BFhkNodHRwOi8vd3d3Lm1pY3Jvc29mdC5j
# b20vcGtpb3BzL2NybC9NaWNDb2RTaWdQQ0EyMDExXzIwMTEtMDctMDguY3JsMGEG
# CCsGAQUFBwEBBFUwUzBRBggrBgEFBQcwAoZFaHR0cDovL3d3dy5taWNyb3NvZnQu
# Y29tL3BraW9wcy9jZXJ0cy9NaWNDb2RTaWdQQ0EyMDExXzIwMTEtMDctMDguY3J0
# MAwGA1UdEwEB/wQCMAAwDQYJKoZIhvcNAQELBQADggIBAISxFt/zR2frTFPB45Yd
# mhZpB2nNJoOoi+qlgcTlnO4QwlYN1w/vYwbDy/oFJolD5r6FMJd0RGcgEM8q9TgQ
# 2OC7gQEmhweVJ7yuKJlQBH7P7Pg5RiqgV3cSonJ+OM4kFHbP3gPLiyzssSQdRuPY
# 1mIWoGg9i7Y4ZC8ST7WhpSyc0pns2XsUe1XsIjaUcGu7zd7gg97eCUiLRdVklPmp
# XobH9CEAWakRUGNICYN2AgjhRTC4j3KJfqMkU04R6Toyh4/Toswm1uoDcGr5laYn
# TfcX3u5WnJqJLhuPe8Uj9kGAOcyo0O1mNwDa+LhFEzB6CB32+wfJMumfr6degvLT
# e8x55urQLeTjimBQgS49BSUkhFN7ois3cZyNpnrMca5AZaC7pLI72vuqSsSlLalG
# OcZmPHZGYJqZ0BacN274OZ80Q8B11iNokns9Od348bMb5Z4fihxaBWebl8kWEi2O
# PvQImOAeq3nt7UWJBzJYLAGEpfasaA3ZQgIcEXdD+uwo6ymMzDY6UamFOfYqYWXk
# ntxDGu7ngD2ugKUuccYKJJRiiz+LAUcj90BVcSHRLQop9N8zoALr/1sJuwPrVAtx
# HNEgSW+AKBqIxYWM4Ev32l6agSUAezLMbq5f3d8x9qzT031jMDT+sUAoCw0M5wVt
# CUQcqINPuYjbS1WgJyZIiEkBMIIHejCCBWKgAwIBAgIKYQ6Q0gAAAAAAAzANBgkq
# hkiG9w0BAQsFADCBiDELMAkGA1UEBhMCVVMxEzARBgNVBAgTCldhc2hpbmd0b24x
# EDAOBgNVBAcTB1JlZG1vbmQxHjAcBgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlv
# bjEyMDAGA1UEAxMpTWljcm9zb2Z0IFJvb3QgQ2VydGlmaWNhdGUgQXV0aG9yaXR5
# IDIwMTEwHhcNMTEwNzA4MjA1OTA5WhcNMjYwNzA4MjEwOTA5WjB+MQswCQYDVQQG
# EwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwG
# A1UEChMVTWljcm9zb2Z0IENvcnBvcmF0aW9uMSgwJgYDVQQDEx9NaWNyb3NvZnQg
# Q29kZSBTaWduaW5nIFBDQSAyMDExMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIIC
# CgKCAgEAq/D6chAcLq3YbqqCEE00uvK2WCGfQhsqa+laUKq4BjgaBEm6f8MMHt03
# a8YS2AvwOMKZBrDIOdUBFDFC04kNeWSHfpRgJGyvnkmc6Whe0t+bU7IKLMOv2akr
# rnoJr9eWWcpgGgXpZnboMlImEi/nqwhQz7NEt13YxC4Ddato88tt8zpcoRb0Rrrg
# OGSsbmQ1eKagYw8t00CT+OPeBw3VXHmlSSnnDb6gE3e+lD3v++MrWhAfTVYoonpy
# 4BI6t0le2O3tQ5GD2Xuye4Yb2T6xjF3oiU+EGvKhL1nkkDstrjNYxbc+/jLTswM9
# sbKvkjh+0p2ALPVOVpEhNSXDOW5kf1O6nA+tGSOEy/S6A4aN91/w0FK/jJSHvMAh
# dCVfGCi2zCcoOCWYOUo2z3yxkq4cI6epZuxhH2rhKEmdX4jiJV3TIUs+UsS1Vz8k
# A/DRelsv1SPjcF0PUUZ3s/gA4bysAoJf28AVs70b1FVL5zmhD+kjSbwYuER8ReTB
# w3J64HLnJN+/RpnF78IcV9uDjexNSTCnq47f7Fufr/zdsGbiwZeBe+3W7UvnSSmn
# Eyimp31ngOaKYnhfsi+E11ecXL93KCjx7W3DKI8sj0A3T8HhhUSJxAlMxdSlQy90
# lfdu+HggWCwTXWCVmj5PM4TasIgX3p5O9JawvEagbJjS4NaIjAsCAwEAAaOCAe0w
# ggHpMBAGCSsGAQQBgjcVAQQDAgEAMB0GA1UdDgQWBBRIbmTlUAXTgqoXNzcitW2o
# ynUClTAZBgkrBgEEAYI3FAIEDB4KAFMAdQBiAEMAQTALBgNVHQ8EBAMCAYYwDwYD
# VR0TAQH/BAUwAwEB/zAfBgNVHSMEGDAWgBRyLToCMZBDuRQFTuHqp8cx0SOJNDBa
# BgNVHR8EUzBRME+gTaBLhklodHRwOi8vY3JsLm1pY3Jvc29mdC5jb20vcGtpL2Ny
# bC9wcm9kdWN0cy9NaWNSb29DZXJBdXQyMDExXzIwMTFfMDNfMjIuY3JsMF4GCCsG
# AQUFBwEBBFIwUDBOBggrBgEFBQcwAoZCaHR0cDovL3d3dy5taWNyb3NvZnQuY29t
# L3BraS9jZXJ0cy9NaWNSb29DZXJBdXQyMDExXzIwMTFfMDNfMjIuY3J0MIGfBgNV
# HSAEgZcwgZQwgZEGCSsGAQQBgjcuAzCBgzA/BggrBgEFBQcCARYzaHR0cDovL3d3
# dy5taWNyb3NvZnQuY29tL3BraW9wcy9kb2NzL3ByaW1hcnljcHMuaHRtMEAGCCsG
# AQUFBwICMDQeMiAdAEwAZQBnAGEAbABfAHAAbwBsAGkAYwB5AF8AcwB0AGEAdABl
# AG0AZQBuAHQALiAdMA0GCSqGSIb3DQEBCwUAA4ICAQBn8oalmOBUeRou09h0ZyKb
# C5YR4WOSmUKWfdJ5DJDBZV8uLD74w3LRbYP+vj/oCso7v0epo/Np22O/IjWll11l
# hJB9i0ZQVdgMknzSGksc8zxCi1LQsP1r4z4HLimb5j0bpdS1HXeUOeLpZMlEPXh6
# I/MTfaaQdION9MsmAkYqwooQu6SpBQyb7Wj6aC6VoCo/KmtYSWMfCWluWpiW5IP0
# wI/zRive/DvQvTXvbiWu5a8n7dDd8w6vmSiXmE0OPQvyCInWH8MyGOLwxS3OW560
# STkKxgrCxq2u5bLZ2xWIUUVYODJxJxp/sfQn+N4sOiBpmLJZiWhub6e3dMNABQam
# ASooPoI/E01mC8CzTfXhj38cbxV9Rad25UAqZaPDXVJihsMdYzaXht/a8/jyFqGa
# J+HNpZfQ7l1jQeNbB5yHPgZ3BtEGsXUfFL5hYbXw3MYbBL7fQccOKO7eZS/sl/ah
# XJbYANahRr1Z85elCUtIEJmAH9AAKcWxm6U/RXceNcbSoqKfenoi+kiVH6v7RyOA
# 9Z74v2u3S5fi63V4GuzqN5l5GEv/1rMjaHXmr/r8i+sLgOppO6/8MO0ETI7f33Vt
# Y5E90Z1WTk+/gFcioXgRMiF670EKsT/7qMykXcGhiJtXcVZOSEXAQsmbdlsKgEhr
# /Xmfwb1tbWrJUnMTDXpQzTGCGZ4wghmaAgEBMIGVMH4xCzAJBgNVBAYTAlVTMRMw
# EQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQKExVN
# aWNyb3NvZnQgQ29ycG9yYXRpb24xKDAmBgNVBAMTH01pY3Jvc29mdCBDb2RlIFNp
# Z25pbmcgUENBIDIwMTECEzMAAAOvMEAOTKNNBUEAAAAAA68wDQYJYIZIAWUDBAIB
# BQCgga4wGQYJKoZIhvcNAQkDMQwGCisGAQQBgjcCAQQwHAYKKwYBBAGCNwIBCzEO
# MAwGCisGAQQBgjcCARUwLwYJKoZIhvcNAQkEMSIEIA/+c/NaF/VXl6sms7adeW5X
# 2RdkBqS/SOPnImXqCizIMEIGCisGAQQBgjcCAQwxNDAyoBSAEgBNAGkAYwByAG8A
# cwBvAGYAdKEagBhodHRwOi8vd3d3Lm1pY3Jvc29mdC5jb20wDQYJKoZIhvcNAQEB
# BQAEggEAuZ+Xy1Q2DOEeRVoj3STCbWfFuQzuvDb0Rkj3Yr/Ed+I/VFEcBa+wyEkc
# R/WNKiVcyB95pkWK+J67vPevqyuupGd1tiSELmqeDEKDwbdRa3hMEMjKQdRr7FnD
# GXiw4tmztQdAItN/1nQibzoOA70PJ9O+U8NLzNsIRYu7Wt1ZU9lug7C17ZEklRtR
# erXNNEAGLGiChRFFDdDdS72peHunEaYm5qOUBlKjm3e/1T75kEeaPj8Dz8aiLj96
# B+x4NW5kN8qWrO9jrvsr647+xfDW8jEx5BoLDGTNLNLWAgPab6zJCZU5QR8cDTv6
# ZcGorHCzcqPk1DQLijC4vwNs6CQB4KGCFygwghckBgorBgEEAYI3AwMBMYIXFDCC
# FxAGCSqGSIb3DQEHAqCCFwEwghb9AgEDMQ8wDQYJYIZIAWUDBAIBBQAwggFYBgsq
# hkiG9w0BCRABBKCCAUcEggFDMIIBPwIBAQYKKwYBBAGEWQoDATAxMA0GCWCGSAFl
# AwQCAQUABCChEUPY5ru09tbtcraGpn8vZ7oBG60HS+2xnf0+ggjEGQIGZh+3MH9L
# GBIyMDI0MDQyODIxMTc0My4zM1owBIACAfSggdikgdUwgdIxCzAJBgNVBAYTAlVT
# MRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQK
# ExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xLTArBgNVBAsTJE1pY3Jvc29mdCBJcmVs
# YW5kIE9wZXJhdGlvbnMgTGltaXRlZDEmMCQGA1UECxMdVGhhbGVzIFRTUyBFU046
# MkFENC00QjkyLUZBMDExJTAjBgNVBAMTHE1pY3Jvc29mdCBUaW1lLVN0YW1wIFNl
# cnZpY2WgghF4MIIHJzCCBQ+gAwIBAgITMwAAAd6eSJ6WnyhEPQABAAAB3jANBgkq
# hkiG9w0BAQsFADB8MQswCQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQ
# MA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBvcmF0aW9u
# MSYwJAYDVQQDEx1NaWNyb3NvZnQgVGltZS1TdGFtcCBQQ0EgMjAxMDAeFw0yMzEw
# MTIxOTA3MTJaFw0yNTAxMTAxOTA3MTJaMIHSMQswCQYDVQQGEwJVUzETMBEGA1UE
# CBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9z
# b2Z0IENvcnBvcmF0aW9uMS0wKwYDVQQLEyRNaWNyb3NvZnQgSXJlbGFuZCBPcGVy
# YXRpb25zIExpbWl0ZWQxJjAkBgNVBAsTHVRoYWxlcyBUU1MgRVNOOjJBRDQtNEI5
# Mi1GQTAxMSUwIwYDVQQDExxNaWNyb3NvZnQgVGltZS1TdGFtcCBTZXJ2aWNlMIIC
# IjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEAtIH0HIX1QgOEDrEWs6eLD/Gw
# OXyxKL2s4I5dJI7hUxCOc0YCjlUfHSKKMwQwf0tjZJQgGRVBLQyXqRH5NqCRQ9to
# SnCOFDWamuFGAlP+OVKeJzjZUMCjR6fgkjrGdegChagrJJjz9E4gp2mmGAjs4lvh
# ceTU/exfak1nfYsNjWS1yErX+FbI+VuVpcAdG7QTfKe/CtLz9tyisA07oOO7KzJL
# 3NSav7DcfcAS9KCzZF64uPamQFx9bVQ8IW50t3sg9nZELih1BwQ+djXaPKlg+dLr
# JkCzSkumrQpEVTIHXHrHo5Tvey52Ic43XqYTSXostP06YajRL3gHGDc3/doTp9Ru
# dWh6ZVzsWQUu6bwqRlxtDtw4dIBYYnF0K+jk61S1F1Kp/zkWSUJcgiSDiybucz1O
# S1RV87SSnqTHubKyAPRCvHHr/mhqqfA5NYs3Mr4EKLUbudQPWm165e9Cnx8TUqlO
# Ocb/U4l56HAo00+Ma33xXQGaiBlN7dLEGQ545DIsD77kfKD8vryl74Otmhk9cloZ
# T+IGIWYv66X86Ld3zfMsAeUdCYf9UY0F9HA/6LG+qHKT8R5vC5dUlj6tPJ9tF+6H
# 2fQBoyGE3HGDq0YrJlLgQASIPGsX2YBkTLx7yt/p2Uohfl3dpAuj18N1rVlM7D5c
# BwC+Pb83cMtUZmUeceUCAwEAAaOCAUkwggFFMB0GA1UdDgQWBBRrMCZvGx5pqmB3
# HMrw6z6do9ASyDAfBgNVHSMEGDAWgBSfpxVdAF5iXYP05dJlpxtTNRnpcjBfBgNV
# HR8EWDBWMFSgUqBQhk5odHRwOi8vd3d3Lm1pY3Jvc29mdC5jb20vcGtpb3BzL2Ny
# bC9NaWNyb3NvZnQlMjBUaW1lLVN0YW1wJTIwUENBJTIwMjAxMCgxKS5jcmwwbAYI
# KwYBBQUHAQEEYDBeMFwGCCsGAQUFBzAChlBodHRwOi8vd3d3Lm1pY3Jvc29mdC5j
# b20vcGtpb3BzL2NlcnRzL01pY3Jvc29mdCUyMFRpbWUtU3RhbXAlMjBQQ0ElMjAy
# MDEwKDEpLmNydDAMBgNVHRMBAf8EAjAAMBYGA1UdJQEB/wQMMAoGCCsGAQUFBwMI
# MA4GA1UdDwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAgEA4pTAexcNpwY69QiC
# zkcOA+zQtnWrIdLoLrB8qUtoPfq1l9ta3XH4YyJrNK7L4azGJUfOSExb4WoryCu4
# tBY3+w4Jf58ZSBP0tPbVxEilxmPj9kUi/C2QFywLPVcRSxdg5IlQ+K1jsTxtuV2a
# aFhnb2n5dCkhywb+r5iOSoFb2bDSu7Ux/ExNCz0xMOIPbyABUas8Dc3KSJIKG92p
# LtVf78twTP1RvO2j/DbxYDwc4IeoFNsNEeaI/swiP5JCYj1UhrJiwgZGO96WY1rQ
# 69tT0IlLP818wSB/Y0cxlRhbwqpYSMiM98cgrFaU0xiG5Z9ZFIdkIrIgA0DRokvi
# ygdC3PNnYyc1+NhjznXAdiMaDBSP+GUtGBA7lLfRnHvwaoEp/KWnblo5Yn+o+EL4
# NczaBdqMhduX6OkZxUA3C0UW6MIlF1lt4fVH5DjUWOAGDibc5MUMai3kNK5WRCCO
# S7uk5U+2V0TjpCUOD/ZaE+lNDFcfriw/UZ+QDBS23qutkz88LBEbqCKtiadNEsuy
# JwGGhguH4QQWNW+JcAZOTqme7yPH/hY9a7SOzPvIXODzb8UyoKT3Arcu/IsDIMc3
# 4XFscDG2DBp3ugtA8zRYYRF0HW6Y8IiJixJ/+Pv0Sod2g3BBhE5Wb5lfXRFfefpt
# GYCeyR42GLTCdVp5WiAsx0YP6eowggdxMIIFWaADAgECAhMzAAAAFcXna54Cm0mZ
# AAAAAAAVMA0GCSqGSIb3DQEBCwUAMIGIMQswCQYDVQQGEwJVUzETMBEGA1UECBMK
# V2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0
# IENvcnBvcmF0aW9uMTIwMAYDVQQDEylNaWNyb3NvZnQgUm9vdCBDZXJ0aWZpY2F0
# ZSBBdXRob3JpdHkgMjAxMDAeFw0yMTA5MzAxODIyMjVaFw0zMDA5MzAxODMyMjVa
# MHwxCzAJBgNVBAYTAlVTMRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdS
# ZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xJjAkBgNVBAMT
# HU1pY3Jvc29mdCBUaW1lLVN0YW1wIFBDQSAyMDEwMIICIjANBgkqhkiG9w0BAQEF
# AAOCAg8AMIICCgKCAgEA5OGmTOe0ciELeaLL1yR5vQ7VgtP97pwHB9KpbE51yMo1
# V/YBf2xK4OK9uT4XYDP/XE/HZveVU3Fa4n5KWv64NmeFRiMMtY0Tz3cywBAY6GB9
# alKDRLemjkZrBxTzxXb1hlDcwUTIcVxRMTegCjhuje3XD9gmU3w5YQJ6xKr9cmmv
# Haus9ja+NSZk2pg7uhp7M62AW36MEBydUv626GIl3GoPz130/o5Tz9bshVZN7928
# jaTjkY+yOSxRnOlwaQ3KNi1wjjHINSi947SHJMPgyY9+tVSP3PoFVZhtaDuaRr3t
# pK56KTesy+uDRedGbsoy1cCGMFxPLOJiss254o2I5JasAUq7vnGpF1tnYN74kpEe
# HT39IM9zfUGaRnXNxF803RKJ1v2lIH1+/NmeRd+2ci/bfV+AutuqfjbsNkz2K26o
# ElHovwUDo9Fzpk03dJQcNIIP8BDyt0cY7afomXw/TNuvXsLz1dhzPUNOwTM5TI4C
# vEJoLhDqhFFG4tG9ahhaYQFzymeiXtcodgLiMxhy16cg8ML6EgrXY28MyTZki1ug
# poMhXV8wdJGUlNi5UPkLiWHzNgY1GIRH29wb0f2y1BzFa/ZcUlFdEtsluq9QBXps
# xREdcu+N+VLEhReTwDwV2xo3xwgVGD94q0W29R6HXtqPnhZyacaue7e3PmriLq0C
# AwEAAaOCAd0wggHZMBIGCSsGAQQBgjcVAQQFAgMBAAEwIwYJKwYBBAGCNxUCBBYE
# FCqnUv5kxJq+gpE8RjUpzxD/LwTuMB0GA1UdDgQWBBSfpxVdAF5iXYP05dJlpxtT
# NRnpcjBcBgNVHSAEVTBTMFEGDCsGAQQBgjdMg30BATBBMD8GCCsGAQUFBwIBFjNo
# dHRwOi8vd3d3Lm1pY3Jvc29mdC5jb20vcGtpb3BzL0RvY3MvUmVwb3NpdG9yeS5o
# dG0wEwYDVR0lBAwwCgYIKwYBBQUHAwgwGQYJKwYBBAGCNxQCBAweCgBTAHUAYgBD
# AEEwCwYDVR0PBAQDAgGGMA8GA1UdEwEB/wQFMAMBAf8wHwYDVR0jBBgwFoAU1fZW
# y4/oolxiaNE9lJBb186aGMQwVgYDVR0fBE8wTTBLoEmgR4ZFaHR0cDovL2NybC5t
# aWNyb3NvZnQuY29tL3BraS9jcmwvcHJvZHVjdHMvTWljUm9vQ2VyQXV0XzIwMTAt
# MDYtMjMuY3JsMFoGCCsGAQUFBwEBBE4wTDBKBggrBgEFBQcwAoY+aHR0cDovL3d3
# dy5taWNyb3NvZnQuY29tL3BraS9jZXJ0cy9NaWNSb29DZXJBdXRfMjAxMC0wNi0y
# My5jcnQwDQYJKoZIhvcNAQELBQADggIBAJ1VffwqreEsH2cBMSRb4Z5yS/ypb+pc
# FLY+TkdkeLEGk5c9MTO1OdfCcTY/2mRsfNB1OW27DzHkwo/7bNGhlBgi7ulmZzpT
# Td2YurYeeNg2LpypglYAA7AFvonoaeC6Ce5732pvvinLbtg/SHUB2RjebYIM9W0j
# VOR4U3UkV7ndn/OOPcbzaN9l9qRWqveVtihVJ9AkvUCgvxm2EhIRXT0n4ECWOKz3
# +SmJw7wXsFSFQrP8DJ6LGYnn8AtqgcKBGUIZUnWKNsIdw2FzLixre24/LAl4FOmR
# sqlb30mjdAy87JGA0j3mSj5mO0+7hvoyGtmW9I/2kQH2zsZ0/fZMcm8Qq3UwxTSw
# ethQ/gpY3UA8x1RtnWN0SCyxTkctwRQEcb9k+SS+c23Kjgm9swFXSVRk2XPXfx5b
# RAGOWhmRaw2fpCjcZxkoJLo4S5pu+yFUa2pFEUep8beuyOiJXk+d0tBMdrVXVAmx
# aQFEfnyhYWxz/gq77EFmPWn9y8FBSX5+k77L+DvktxW/tM4+pTFRhLy/AsGConsX
# HRWJjXD+57XQKBqJC4822rpM+Zv/Cuk0+CQ1ZyvgDbjmjJnW4SLq8CdCPSWU5nR0
# W2rRnj7tfqAxM328y+l7vzhwRNGQ8cirOoo6CGJ/2XBjU02N7oJtpQUQwXEGahC0
# HVUzWLOhcGbyoYIC1DCCAj0CAQEwggEAoYHYpIHVMIHSMQswCQYDVQQGEwJVUzET
# MBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMV
# TWljcm9zb2Z0IENvcnBvcmF0aW9uMS0wKwYDVQQLEyRNaWNyb3NvZnQgSXJlbGFu
# ZCBPcGVyYXRpb25zIExpbWl0ZWQxJjAkBgNVBAsTHVRoYWxlcyBUU1MgRVNOOjJB
# RDQtNEI5Mi1GQTAxMSUwIwYDVQQDExxNaWNyb3NvZnQgVGltZS1TdGFtcCBTZXJ2
# aWNloiMKAQEwBwYFKw4DAhoDFQBooFKKzLjLzqmXxfLbYIlkTETa86CBgzCBgKR+
# MHwxCzAJBgNVBAYTAlVTMRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdS
# ZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xJjAkBgNVBAMT
# HU1pY3Jvc29mdCBUaW1lLVN0YW1wIFBDQSAyMDEwMA0GCSqGSIb3DQEBBQUAAgUA
# 6di0mjAiGA8yMDI0MDQyODE5NDIxOFoYDzIwMjQwNDI5MTk0MjE4WjB0MDoGCisG
# AQQBhFkKBAExLDAqMAoCBQDp2LSaAgEAMAcCAQACAgqoMAcCAQACAhHjMAoCBQDp
# 2gYaAgEAMDYGCisGAQQBhFkKBAIxKDAmMAwGCisGAQQBhFkKAwKgCjAIAgEAAgMH
# oSChCjAIAgEAAgMBhqAwDQYJKoZIhvcNAQEFBQADgYEASe30Fg8T6CNdeaWkONuR
# siTClbylzcg7CSxFfDv/+kl5xc1vPvprSjKKGvpAN95P6krveJ6OBUyGBo8xTF88
# mxOPxDKNlmcURp5gtDYYGA5ZyPQ3ULMZgf1mO2CKmyLUx5D9pASxBSNYV1coSSdh
# DaQQc2taduEPEJkBZRbR+icxggQNMIIECQIBATCBkzB8MQswCQYDVQQGEwJVUzET
# MBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMV
# TWljcm9zb2Z0IENvcnBvcmF0aW9uMSYwJAYDVQQDEx1NaWNyb3NvZnQgVGltZS1T
# dGFtcCBQQ0EgMjAxMAITMwAAAd6eSJ6WnyhEPQABAAAB3jANBglghkgBZQMEAgEF
# AKCCAUowGgYJKoZIhvcNAQkDMQ0GCyqGSIb3DQEJEAEEMC8GCSqGSIb3DQEJBDEi
# BCDFVUdzmms/grPK5uVsCdPjMuJyoDx4Yyq42q5a/WhNxjCB+gYLKoZIhvcNAQkQ
# Ai8xgeowgecwgeQwgb0EII4+I58NwV4QEEkCf+YLcyCtPnD9TbPzUtgPjgdzfh17
# MIGYMIGApH4wfDELMAkGA1UEBhMCVVMxEzARBgNVBAgTCldhc2hpbmd0b24xEDAO
# BgNVBAcTB1JlZG1vbmQxHjAcBgNVBAoTFU1pY3Jvc29mdCBDb3Jwb3JhdGlvbjEm
# MCQGA1UEAxMdTWljcm9zb2Z0IFRpbWUtU3RhbXAgUENBIDIwMTACEzMAAAHenkie
# lp8oRD0AAQAAAd4wIgQgUHcfQAQGk5LWQqVR6YlBRxCGqeU9+0ZQpF6zsZm3V8gw
# DQYJKoZIhvcNAQELBQAEggIAlPsNFdXiruUDRXQMcSAk/iRduk5aKV66zuXg2a9L
# chQz12kFvP/MYQ2Xv3O4SfEnIXZB07XbflJO0bpY7d4FCyfNiozS4H/bj4sk2oRF
# 4eJUnZXyjcIqq++ya0Y0O3XRwfoFqwA13B+XWCMY6tOu0eONZGaLrDj8DsgLD2NA
# QAiByrCosZnuUfjxVVXovScHbrnTP1VNgu6oQtkMOOTA2yXR7q1rmWjXsW9HGUHM
# TFPj8C7wMK1ZjWCPzzuAxJ6A2YSeyNmeI59DYzNeN3nlaCakCtVX59mi6Hb2QN0r
# sdeqO/x/WyVH//+9mdapcY/LGats+9MV4EByRET/PP0J7sRPNSijGxJcVj4Z8JCa
# JV9jlkwWKa0sTkViLe+0j6hNep4xPvDPjxKDB1+hfhL6klxLJtdYBbmlSFlmlEUt
# yEMrnzWvRq+GYjEIGaq4CRDNJmkK9ZZGz74rK9QZ5vg5NtNuGf2rtWi+zsXtPKzy
# NGdMBdEMKxQE0U5lr0eAmqXrNeHUv8Ba+wHO6eHeVFzzZCS7mceYKHOfd/DBSoIx
# GKMPISv8xmK8FFF6lJ2hlak7XLxFjT+RG1g1XJcxDkTDgU81xzxfp/FCj9tMRTWn
# O/JhmTrv7e6DACzX6l8paLmpi7r6d9wLfCuAn2nNy3YEboBzeDpapEVVSRsG/eyo
# nDg=
# SIG # End signature block
