//go:build linux && amd64

package audio_transcoder

/*
#cgo CFLAGS: -I${SRCDIR}/3rd/wrapper -I${SRCDIR}/3rd/include
#cgo LDFLAGS: -L${SRCDIR}/3rd/lib/linux64 -lfaad -lfaac -lopus -lm -lstdc++ -lpthread
*/
import "C"
