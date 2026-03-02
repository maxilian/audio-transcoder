//go:build windows && amd64

package audio_transcoder

/*
#cgo CFLAGS: -I${SRCDIR}/3rd/wrapper -I${SRCDIR}/3rd/include
#cgo LDFLAGS: -L${SRCDIR}/3rd/lib/win64 -lfaad -lfaac -lopus
*/
import "C"
