add_library(ConferenceLibrary
    src/Person.cpp
    src/Participant.cpp
    src/StudentParticipant.cpp
    src/SpeakerParticipant.cpp
    src/Conference.cpp
    src/RegistrationStatus.cpp
    src/Registration.cpp
)
target_include_directories(ConferenceLibrary PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)